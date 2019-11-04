/*
** EPITECH PROJECT, 2019
** my_revstr
** File description:
** void
*/

#include <unistd.h>
#include <stdlib.h>

int my_strlen(char *str);

char *my_revstr(char *str)
{
    char *str2 = malloc(sizeof(char) * (my_strlen(str) + 1));
    int i = my_strlen(str) - 1;
    int x = 0;

    for (; i >= 0; i--) {
        str2[x] = str[i];
        x++;
    }
    str2[x] = '\0';
    return (str2);
}
