/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** bsq.h
*/

#ifndef MY_LS_
#define MY_LS_

#include "my.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <fcntl.h>
#include <sys/sysmacros.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <linux/stat.h>
#include <grp.h>
#include <time.h>
#include <pwd.h>

typedef struct base_s
{
    DIR *dir;
    struct dirent *rd;
    struct stat st;
    struct passwd *pas;
    struct group *guid;
    char *time;
    char *file;
    int i;
} base_t;

int documentation(void);

void type(base_t *base);

int total(char *arg, base_t *base);
int my_ls_l(char *arg, base_t *base);
void help_while_my_ls_l(char *arg, base_t *base);
void if_help_while_my_ls_l(base_t *base);

void help_help(base_t *base);
void print_informations(base_t *base);

int error_total(struct stat stat, DIR *dir, char *arg);

void my_ls_d(int ac, char **arg);

int put_long(long number);

void help_total(char *arg, base_t *base, DIR *dir);

int error(int ac, char **av, base_t *base);

int help_main_flags_d(int ac, char **av);
int my_ls(char *arg);
int main(int ac, char **av);

#endif /*MY_LS_*/