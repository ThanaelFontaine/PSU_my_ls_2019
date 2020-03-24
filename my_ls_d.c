/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** my_ls_d.c
*/

#include "include/my_ls.h"

void my_ls_d(int ac, char **arg)
{
    if (ac == 2) {
        my_putstr(".");
        my_putchar('\n');
    }
    for (int i = 2; arg[i] != NULL; i += 1)
        my_putstr(arg[i]);
}