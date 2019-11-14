/*
** EPITECH PROJECT, 2019
** bsq.c
** File description:
** Gael Baron's bsq.c made the 11/04/2019
*/

#include "../include/my.h"
#include "../include/bsq.h"

void info_square(maximum max);

void freeing(char *buff, char **tab)
{
    free(buff);
    for (int i = 0; tab[i]; i++)
        free(tab[i]);
    free(tab);
}

int print_line(char **tab, int i, int one_two)
{
    for (int j = 0; tab[i][j]; j++) {
        if (tab[i][j] == 'o') {
            if (one_two % 2 == 0)
                my_putstr("\033[0;35mo\033[0m");
            else
                my_putstr("\033[0;36mo\033[0m");
            one_two++;
        }
        else if (tab[i][j] == 'x')
                my_putstr("\033[0;33mx\033[0m");
        else if (tab[i][j] == '.')
            if (one_two % 2 == 0)
                my_putstr("\033[0;34m.\033[0m");
            else
                my_putstr("\033[0;31m.\033[0m");
        else
            my_putchar(tab[i][j]);
        one_two++;
    }
    return (one_two);
}

void map_print(char **tab)
{
    int one_two = 0;

    for (int i = 1; tab[i]; i++) {
        one_two = print_line(tab, i, one_two);
        my_putchar('\n');
    }
}

char *converter(char *av, char *buffer)
{
    struct stat status;
    int file_descriptor = open(av, O_RDONLY);
    int err;

    if (file_descriptor == -1)
        return (NULL);
    err = stat(av, &status);
    if (err == -1)
        return (NULL);
    buffer = malloc(sizeof(char) * (status.st_size + 1));
    if (!buffer)
        return (NULL);
    err = read(file_descriptor, buffer, (status.st_size + 1));
    if (err == -1)
        return (NULL);
    buffer[status.st_size] = '\0';
    err = close(file_descriptor);
    if (err == -1)
        return (NULL);
    return (buffer);
}

int bsq(int ac, char **av)
{
    char *buff = converter(av[1], buff);
    maximum max;
    char **tab;

    if (!buff)
        return (84);
    if (error_gestion(ac, av, buff) == 84)
        return (84);
    max.size = 0;
    max.i_pos = 0;
    max.j_pos = 1;
    tab = my_str_to_word_tab(buff);
    max = algo(tab, max);
    tab = mapping(tab, max);
    map_print(tab);
    info_square(max);
    freeing(buff, tab);
    return (0);
}
