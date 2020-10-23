/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** tests_navy.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "navy.h"

Test(check_error_test, check_no_errror)
{
    int ac = 2;
    char *av[] = {"./test_run", "pos"};

    cr_assert_eq(check_error(ac, av), 1);
}

Test(check_pos_test, pos)
{
    char *pos = "A1";

    cr_assert_eq(check_pos(pos), 0);
}

Test(check_pos_test, pos_1)
{
    char *pos = "P1";

    cr_assert_eq(check_pos(pos), 1);
}