/*
** EPITECH PROJECT, 2019
** str_upcase
** File description:
** str up case
*/

#include <stdio.h>

char *my_strupcase(char *str)
{
    char c;
    int i = 0;

    for (; str[i] != '\0'; i++) {
        if (str[i] <= 'z' && str[i] >= 'a') {
            c = str[i];
            str[i] = c - 32;
        }
    }
    return (str);
}
