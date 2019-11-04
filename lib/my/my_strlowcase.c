/*
** EPITECH PROJECT, 2019
** my_strlowcase
** File description:
** str low case
*/

#include <stdio.h>

char *my_strlowcase(char *str)
{
    char c;
    int i = 0;

    for (; str[i] != '\0'; i++) {
        if (str[i] <= 'Z' && str[i] >= 'A') {
            c = str[i];
            str[i] = c + 32;
        }
    }
    return (str);
}
