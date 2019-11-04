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
    int len;
    int size = my_n_count(buff);

    if (size > 1) {
        tab = my_str_to_word_tab(buff);
        len = my_strlen(tab[1]);
        for (int i = 2; tab[i]; i++)
            if (my_strlen(tab[i]) != len)
                return (84);
    }
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
    int err = 0;

    if (ac > 2)
        return (84);
    if (my_n_count(buff) <= 0)
        return (84);
    if (is_it_number(buff) == NO)
        return (84);
    if (is_it_a_map(buff) == NO)
        return (84);
    err = error_next(buff);
    return (err);
}
