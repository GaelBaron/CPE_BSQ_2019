/*
** EPITECH PROJECT, 2019
** bsq.c
** File description:
** Gael Baron's bsq.c made the 11/04/2019
*/

#include "../include/my.h"
#include "../include/bsq.h"

void freeing(char *buff, char **tab)
{
    free(buff);
    for (int i = 0; tab[i]; i++)
        free(tab[i]);
    free(tab);
}

void map_print(char **tab)
{
    for (int i = 1; tab[i]; i++) {
        if (my_strlen(tab[i]) > 1 && tab[i][0] != '\n') {
            my_putstr(tab[i]);
            my_putchar('\n');
        }
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
    if (special_case(buff) == 1)
        return (0);
    max.size = 0;
    max.i_pos = 0;
    max.j_pos = 1;
    tab = my_str_to_word_tab(buff);
    max = algo(tab, max);
    tab = mapping(tab, max);
    map_print(tab);
    freeing(buff, tab);
    return (0);
}
