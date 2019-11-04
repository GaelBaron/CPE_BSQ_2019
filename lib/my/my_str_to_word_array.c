/*
** EPITECH PROJECT, 2019
** my_str_to_word_array
** File description:
** str to word array
*/

#include <unistd.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

int my_strlen(char const *str);

int is_a_char(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    if (c >= 'A' && c <= 'Z')
        return (1);
    if (c >= 'a' && c <= 'z')
        return (1);
    return (0);
}

int count_words(char const *str)
{
    int word_nb = 0;
    int i = 0;

    while (str[i] != '\0') {
        if (i == 0 && is_a_char(str[i] == 1))
            word_nb++;
        else if (is_a_char(str[i]) == 1 && is_a_char(str[i - 1]) == 0)
            word_nb++;
        i++;
    }
    return (word_nb);
}

char **boucler(char const *str, char **tab)
{
    int x = 0;
    int y = 0;

    for (int j = 0;str[j] != '\0'; j++) {
        if (is_a_char(str[j]) == 0 && j == 0)
            j++;
        else if (is_a_char(str[j]) == 1) {
            tab[y][x] = str[j];
            x++;
        }
        else if (is_a_char(str[j]) == 0
                && (is_a_char(str[j - 1]) == 1 || j == 0)) {
            tab[y][x] = '\0';
            x = 0;
            y++;
        }
    }
    tab[y][x] = '\0';
    tab[y + 1] = NULL;
    return (tab);
}

char **my_str_to_word_array(char const *str)
{
    char **tab = malloc(sizeof(char *) * (count_words(str) + 1));

    for (int i = 0; i <= count_words(str); i++)
        tab[i] = malloc(sizeof(char) * (my_strlen(str) + 1));
    tab = boucler(str, tab);
    return (tab);
}
