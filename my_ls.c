/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** my_ls.c
*/

#include "include/my_ls.h"

int my_ls(char *arg)
{
    DIR* directory = opendir(arg);
    struct dirent *rd;

    while ((rd = readdir(directory))) {
        if (rd == NULL)
            break;
        if (rd->d_name[0] != '.') {
            my_putstr(rd->d_name);
            my_putchar('\n');
        }
    }
    closedir(directory);
    return (0);
}

int help_main_flags_d(int ac, char **av)
{
    if (my_strcmp(av[1], "-d") == 0) {
        if (!opendir(av[2]))
            return (84);
        my_ls_d(ac, av);
        return (0);
    }
    if (av[1][0] != '-') {
        if (!opendir(av[1]))
            return (84);
        my_ls(av[1]);
    }
    return (0);
}

int main(int ac, char **av)
{
    base_t *base = malloc(sizeof(base_t));

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0')
        documentation();
    if (ac == 1)
        my_ls(".");
    else {
        if (my_strcmp(av[1], "-l") == 0) {
            error(ac, av, base);
        }
        help_main_flags_d(ac, av);
    }
    return (0);
}

int error(int ac, char **av, base_t *base)
{
    if (ac == 3)
        if (!opendir(av[2]))
                exit(84);
    else if (ac == 2)
        my_ls_l(".", base);
    else
        my_ls_l(av[2], base);
    return (0);
}