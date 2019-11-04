/*
** EPITECH PROJECT, 2019
** bsq.h
** File description:
** Gael Baron's bsq.h made the 11/04/2019
*/

#ifndef BSQ_H
#define BSQ_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define YES 1
#define NO 0

typedef struct maximum_type
{
    int j_pos;
    int i_pos;
    int size;
} maximum;

/*bsq.c*/
int main(int ac, char **av);
int bsq(int ac, char **av);
char *converter(char *av, char *buffer);
void freeing(char *buff, char **tab);

/*algo.c*/
int is_it_op(char c);
int test_line(char *str, int i, int size);
int test_columns(char **str, int i, int j, int size);
maximum algo(char **str, maximum max);

/*my_str_to_word_tab.c*/
char **my_str_to_word_tab(char *str);
int my_ncout(char *str);

/*mapping.c*/
char **mapping(char **tab, maximum max);

#endif
