/*
** EPITECH PROJECT, 2019
** tests_error.c
** File description:
** Gael Baron's tests_error.c made the 11/04/2019
*/

#include <criterion/criterion.h>
#include <signal.h>
#include <stddef.h>
#include "../include/my.h"
#include "../include/bsq.h"

Test(bsq, not_matching_line_one)
{
    int ac = 2;
    char *av[] = {"./bsq", "map/this_file_doesnt_exist", NULL};
    char buff[] = "3\n...o\no...\n....\n....";

    cr_expect(error_gestion(ac, av, buff) == 84);
}

Test(bsq, matching_line_one)
{
    int ac = 2;
    char *av[] = {"./bsq", "map/this_file_doesnt_exist", NULL};
    char buff[] = "3\n...o\no...\n....";

    cr_expect(error_gestion(ac, av, buff) == 0);
}

Test(bsq, no_solve)
{
    int ac = 2;
    char *av[] = {"./bsq", "map/this_file_doesnt_exist", NULL};
    char buff[] = "3\noooo\noooo\noooo";

    cr_expect(error_gestion(ac, av, buff) == 84);
}
