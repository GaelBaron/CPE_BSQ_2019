/*
** EPITECH PROJECT, 2019
** str_to_word_tab.c
** File description:
** Gael Baron's str_to_word_tab.c made the 11/04/2019
*/

#include "../include/bsq.h"
#include "../include/my.h"

int my_ncount(char *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '\n')
            count++;
    return (count);
}

char **my_str_to_word_tab(char *str)
{
    int lines = my_ncount(str);
    char **tab = malloc(sizeof(char *) * (lines + 2));
    int n = 0;
    int j = 0;

    for (int i = 0; i < lines + 2; i++)
        tab[i] = malloc(sizeof(char) * (my_strlen(str) + 1));
    for (int i = 0; str[i] != '\0'; i++, n++) {
        if (str[i] == '\n') {
            i++;
            tab[j][n] = '\0';
            j++;
            n = 0;
            tab[j][n] = str[i];
        }
        else
            tab[j][n] = str[i];
    }
    tab[j][n] = '\0';
    tab[lines + 1] = NULL;
    return (tab);
}
