/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** Gael Baron's main.c made the 11/04/2019
*/

#include "../include/my.h"
#include "../include/bsq.h"

int main(int ac, char **av)
{
    if (ac == 1) {
        my_putstr("DEMERDE TOI CONNARD\n");
    }
    else
        return (bsq(ac, av));
    return (0);
}
