/*
** EPITECH PROJECT, 2019
** error.c
** File description:
** Gael Baron's error.c made the 11/04/2019
*/

#include "../include/my.h"
#include "../include/bsq.h"

int error_next(char *buff)
{
    char **tab;
    int i = 0;
    int nb = 0;

    if (my_n_count(buff) > 1) {
        tab = my_str_to_word_tab(buff);
        for (int i = 1; tab[i]; i++)
            if (my_strlen(tab[i]) != my_strlen(tab[1])
                && my_strlen(tab[i]) != 0)
                return (84);
    }
    while (buff[i] != '\n')
        i++;
    for (; buff[i] != '\0'; i++)
        if (buff[i] == '.')
            nb++;
    if (nb == 0)
        return (84);
    return (not_matching(buff));
}

int not_matching(char *buff)
{
    int size = 0;
    char *str;
    int j = 0;

    for (int i = 0; buff[i] != '\n'; i++)
        size++;
    str = malloc(sizeof(char) * (size + 1));
    if (!str)
        return (84);
    for (; buff[j] != '\n'; j++)
        str[j] = buff[j];
    str[j] = '\0';
    if (my_atoi(str) != my_n_count(buff) - 1)
        return (84);
    return (0);
}

int is_it_number(char *buff)
{
    for (int i = 0; buff[i] != '\n' && buff[i] != '\0'; i++)
        if (buff[i] < '0' || buff[i] > '9')
            return (NO);
    return (YES);
}

int is_it_a_map(char *buff)
{
    int i = 0;

    while (buff[i] != '\n' && buff[i] != '\0')
        i++;
    for (;buff[i] != '\0'; i++)
        if (buff[i] != '\n' && buff[i] != 'o'
            && buff[i] != '.')
            return (NO);
    return (YES);
}

int error_gestion(int ac, char **av, char *buff)
{
    if (ac > 2)
        return (84);
    if (my_n_count(buff) <= 0)
        return (84);
    if (is_it_number(buff) == NO)
        return (84);
    if (is_it_a_map(buff) == NO)
        return (84);
    return (error_next(buff));
}
