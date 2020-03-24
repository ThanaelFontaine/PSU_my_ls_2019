/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** data.c
*/

#include "include/my_ls.h"

void type(base_t *base)
{
    my_putstr((__S_IFDIR & base->st.st_mode) ? "d" : "-");
    my_putstr((base->st.st_mode & S_IRUSR) ? "r" : "-");
    my_putstr((base->st.st_mode & S_IWUSR) ? "w" : "-");
    my_putstr((base->st.st_mode & S_IXUSR) ? "x" : "-");
    my_putstr((base->st.st_mode & S_IRGRP) ? "r" : "-");
    my_putstr((base->st.st_mode & S_IWGRP) ? "w" : "-");
    my_putstr((base->st.st_mode & S_IXGRP) ? "x" : "-");
    my_putstr((base->st.st_mode & S_IROTH) ? "r" : "-");
    my_putstr((base->st.st_mode & S_IWOTH) ? "w" : "-");
    my_putstr((base->st.st_mode & S_IXOTH) ? "x" : "-");
}