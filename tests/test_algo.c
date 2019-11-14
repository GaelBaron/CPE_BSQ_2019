/*
** EPITECH PROJECT, 2019
** test_algo.c
** File description:
** Gael Baron's test_algo.c made the 11/04/2019
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <signal.h>
#include <stddef.h>
#include "../include/bsq.h"
#include "../include/my.h"

char *converter(char *av, char *buffer);

void all_print(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(bsq, out_exit, .init=all_print)
{
    int ac = 2;
    char *av[] = {"./bsq", "tests/map/map_test_10_1", NULL};
    char buff[] = "o\no\nx\n.\n.\no\n.\n.\n.\n.\n";

    bsq(ac, av);
    cr_assert_stdout_eq_str(buff, "");
}

Test(bs_sec, out_exit, .init=all_print)
{
    int ac = 2;
    char *av[] = {"./bsq", "tests/map/map_test_1_10", NULL};
    char buff[] = "oxooooooo..........\n";

    bsq(ac, av);
    cr_assert_stdout_eq_str(buff, "");
}

Test(medium, out_exit, .init=all_print)
{
    int ac = 2;
    char *buffer;
    char *av[] = {"./bsq", "tests/map/map_100_100", NULL};
    char *buff = converter("tests/map/solved_map_100_100", buffer);

    bsq(ac, av);
    cr_assert_stdout_eq_str(buff, "");
}
