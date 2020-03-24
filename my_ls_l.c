/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** my_ls_l.c
*/

#include "include/my_ls.h"

void print_informations(base_t *base)
{
    put_long(base->st.st_nlink);
    my_putstr(" ");
    my_putstr(base->pas->pw_name);
    my_putstr(" ");
    my_putstr(base->guid->gr_name);
    my_putstr(" ");
    put_long(base->st.st_size);
    my_putstr(" ");
}

void help_help(base_t *base)
{
    for (; base->time[base->i] != ' '; base->i += 1);
    for (int count = 2; count > 0 && base->time[base->i]; base->i += 1) {
        if (base->time[base->i] == ':')
            count -= 1;
        if (count != 0)
            my_putchar(base->time[base->i]);
    }
}

void if_help_while_my_ls_l(base_t *base)
{
    if (base->rd->d_name[0] != '.') {
        lstat(base->file, &base->st);
        base->pas = getpwuid(base->st.st_uid);
        base->guid = getgrgid(base->st.st_gid);
        type(base);
        my_putstr(" ");
        print_informations(base);
        base->time = ctime(&(base->st.st_atime));
        base->time[my_strlen(base->time) - 1] = 0;
        help_help(base);
        my_putstr(" ");
        my_putstr(base->rd->d_name);
        my_putstr("\n");
    }
}

void help_while_my_ls_l(char *arg, base_t *base)
{
    while ((base->rd = readdir(base->dir)) != NULL) {
        base->i = 0;
        base->file = malloc(sizeof(char) * (my_strlen(arg)
        + my_strlen(base->rd->d_name) + 2));
        for (int j = 0; j < my_strlen(arg) + my_strlen(base->rd->d_name)
        + 2; base->file[j] = 0, j += 1);
        my_strcat(base->file, arg);
        if (base->file[my_strlen(base->file) - 1] != '/')
            my_strcat(base->file, "/\0");
        my_strcat(base->file, base->rd->d_name);
        if_help_while_my_ls_l(base);
    }
}

int my_ls_l(char *arg, base_t *base)
{
    base->dir = opendir(arg);
    base->pas = malloc(sizeof(base->pas));
    base->guid = malloc(sizeof(base->guid));
    base->time = NULL;
    base->file = arg;
    base->i = 0;

    total(arg, base);
    help_while_my_ls_l(arg, base);
    closedir(base->dir);
    return (0);
}