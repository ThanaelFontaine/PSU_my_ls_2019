/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** documentation.c
*/

#include "include/my_ls.h"

int documentation(void)
{
    write(1, "HOW TO USE MY_LS:\n\n", 22);
    write(1, "You need to execute the programm and right", 43);
    write(1, "like you want on the original ls.\n", 35);
    write(1, "Exemple:   ./my_ls [directory]\n", 32);
    return (0);
}