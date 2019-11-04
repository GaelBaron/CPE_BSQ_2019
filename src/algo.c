/*
** EPITECH PROJECT, 2019
** algo.c
** File description:
** Gael Baron's algo.c made the 11/04/2019
*/

#include "../include/my.h"
#include "../include/bsq.h"

int is_it_ok(char c)
{
    if (c == '.')
        return (YES);
    return (NO);
}

int test_line(char *str, int i, int size)
{
    for (int j = i; i <= (j + size); i++) {
        if (str[i] == '\0')
            return (NO);
        if (is_it_ok(str[i]) == NO)
            return (NO);
    }
    return (YES);
}

int test_columns(char **str, int i, int j, int size)
{
    for (int n = j; j <= (n + size); j++) {
        if (str[j] == NULL)
            return (NO);
        if (test_line(str[j], i, size) == NO)
            return (NO);
    }
    return (YES);
}

int test_squares(char **str, int i, int j, int size)
{
    if (test_columns(str, i, j, size) == YES)
        while (test_columns(str, i, j, size) == YES
            && size <= my_atoi(str[0]))
            size++;
    return (size);
}

maximum algo(char **str, maximum max)
{
    int i = 0;

    for (int j = 1; str[j] != NULL; j++) {
        i = 0;
        while (str[j][i] != '\0') {
            if (is_it_ok(str[j][i]) == NO)
                i++;
            else if (max.size < test_squares(str, i, j, max.size)) {
                max.j_pos = j;
                max.i_pos = i;
                max.size = test_squares(str, max.i_pos, max.j_pos, max.size);
                i++;
            }
            else
                i++;
        }
    }
    return (max);
}
