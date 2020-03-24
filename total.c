/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** total.c
*/

#include "include/my_ls.h"

int total(char *arg, base_t *base)
{
    DIR *dir;

    if (arg == NULL)
        dir = opendir(".");
    else
        dir = opendir(arg);
    help_total(arg, base, dir);
    my_putstr("total ");
    my_put_nbr(base->i / 2);
    my_putchar('\n');
    closedir(dir);
    return (0);
}

void help_total(char *arg, base_t *base, DIR *dir)
{
    while (((base->rd = readdir(dir))) != NULL) {
        base->file = malloc(sizeof(char) * (my_strlen(arg)
        + my_strlen(base->rd->d_name) + 2));
        for (int j = 0; j < my_strlen(arg) + my_strlen(base->rd->d_name)
        + 2; base->file[j] = 0, j += 1);
        my_strcat(base->file, arg);
        if (base->file[my_strlen(base->file) - 1] != '/')
            my_strcat(base->file, "/\0");
        my_strcat(base->file, base->rd->d_name);
        if (base->rd->d_name[0] != '.') {
            lstat(base->file, &base->st);
            base->i += base->st.st_blocks;
        }
        free(base->file);
    }
}