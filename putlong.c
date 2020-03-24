/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** putlong.c
*/

#include "include/my_ls.h"

int put_long(long number)
{
    if (number < 0) {
        number = number * (-1);
        my_putchar('-');
    }
    if (number >= 10)
        my_put_nbr(number / 10);
    number = number % 10;
    my_putchar(number + 48);
    return (0);
}