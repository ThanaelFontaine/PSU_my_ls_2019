/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** error.c
*/

#include "include/my_ls.h"

int error_total(struct stat stat, DIR *dir, char *arg)
{
    if (!dir) {
        if (lstat(arg, &stat) != - 1)
            return (stat.st_blocks / 2);
        else {
            write (1, "WARNING: Empty or none existing file\n", 38);
            return (84);
        }
    }
    return (0);
}