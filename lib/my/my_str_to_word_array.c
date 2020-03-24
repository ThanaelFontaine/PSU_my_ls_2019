/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** my_str_to_word_array2.c
*/

#include <stdlib.h>
#include <unistd.h>

int compter_caractere(char *str, char c);
int compter_avant(char *str, char c);
char *my_strndup(char *str, int a);

char **str_to_word_array(char *str, char c)
{
    char **tableau = malloc(sizeof(char *) * (compter_caractere(str, c) + 1));
    int i = 0;

    for (int j = 0; str[j] != '\0'; j += 1) {
        tableau[i] = my_strndup(str + j, compter_avant(str + j, c));
        if (str[j] != '.' && str[j] != 'o' && str[j] != '\n'
        && str[j] > '9' && str[j] < '0') {
            write (2, "WARNING: Empty or wrong map\n", 29);
            return (NULL);
        }
        i += 1;
        j += compter_avant(str + j, c);
    }
    tableau[i] = NULL;
    return (tableau);
    for (int y = 0; tableau[y]; y += 1)
        free(tableau[y]);
    free(tableau);
}