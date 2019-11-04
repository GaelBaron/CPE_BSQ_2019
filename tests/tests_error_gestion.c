/*
** EPITECH PROJECT, 2019
** tests_error_gestion.c
** File description:
** Gael Baron's tests_error_gestion.c made the 11/04/2019
*/

#include <criterion/criterion.h>
#include <signal.h>
#include <stddef.h>
#include "../include/my.h"
#include "../include/bsq.h"

Test(bsq, wrong_filepath)
{
    int ac = 2;
    char *av[] = {"./bsq", "map/this_file_doesnt_exist", NULL};

    cr_expect(bsq(ac, av) == 84);
}

Test(bsq, not_a_nb_first_line)
{
    int ac = 2;
    char *av[] = {"./bsq", "../map/map", NULL};
    char buff[] = "aezrtazr";

    cr_expect(error_gestion(ac, av, buff) == 84);
}

Test(bsq, not_a_line)
{
    int ac = 2;
    char *av[] = {"./bsq", "../map/map", NULL};
    char buff[] = "1\n....o..oxDR";

    cr_expect(error_gestion(ac, av, buff) == 84);
}

Test(bsq, line_arent_same_size)
{
    int ac = 2;
    char *av[] = {"./bsq", "../map/map", NULL};
    char buff[] = "2\n....o..o\no..ooooo.";

    cr_expect(error_gestion(ac, av, buff) == 84);
}

Test(bsq, is_ok)
{
    int ac = 2;
    char *av[] = {"./bsq", "../map/map", NULL};
    char buff[] = "2\n....o..o\no..ooooo";

    cr_expect(error_gestion(ac, av, buff) == 0);
}
