/*
** EPITECH PROJECT, 2019
** my_strstr
** File description:
** strstr
*/

#include "my.h"
#include <stddef.h>
#include <stdlib.h>

char *my_strstr(char *str1, char *str2)
{
    char *res = malloc(sizeof(char) * (my_strlen(str1) + my_strlen(str2)) + 1);
    int tmp = 0;

    for (int x = 0; str1[x]; x++)
        res[x] = str1[x];
    for (int y = my_strlen(str1); str2[tmp]; y++) {
        res[y] = str2[tmp];
        tmp++;
    }
    res[my_strlen(str1) + my_strlen(str2) + 1] = '\0';
    return (res);
}
