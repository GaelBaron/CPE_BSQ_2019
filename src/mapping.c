/*
** EPITECH PROJECT, 2019
** mapping.c
** File description:
** Gael Baron's mapping.c made the 11/04/2019
*/

#include "../include/bsq.h"
#include "../include/my.h"

char **mapping(char **tab, maximum max)
{
    int i = max.i_pos;
    int j = max.j_pos;

    if (j < (max.j_pos + max.size)) {
        while (j < (max.j_pos + max.size)) {
            while (i < (max.i_pos + max.size)) {
                tab[j][i] = 'x';
                i++;
            }
            j++;
            i = max.i_pos;
        }
    }
    return (tab);
}
