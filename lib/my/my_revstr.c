/*
** EPITECH PROJECT, 2019
** my_revstr
** File description:
** reverse str
*/

char *my_revstr(char *str)
{
    int i = 0;
    int j = 0;
    int p = 0;
    char temp;

    while (str[p])
        p += 1;
    p -= 1;
    j = p;
    while (i <= p/2) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i += 1;
        j -= 1;
    }
    return (str);
}