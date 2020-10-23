/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** tests_map.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "matchstick.h"

Test(matchstick, get_request_functional)
{
    char *argv[] = {"./test_run", "4", "4"};
    struct matchstick *request = request_all(argv);

    cr_expect_eq(request->size, 4);
    free(request);
}

Test(matchstick, request_null)
{
    char *argv[] = {"./test_run", "-1", "-1"};
    struct matchstick *request = request_all(argv);

    cr_expect_null(request);
    free(request);
}

Test(matchstick, check_stick)
{
    char *argv[] = {"./test_run", "4", "4"};
    struct matchstick *request = request_all(argv);

    draw_sticks(request);
    cr_expect_eq(check_sticks(request), 16);
    free(request);
}

Test(matchstick, empty_line_line_over)
{
    char *argv[] = {"./test_run", "4", "4"};
    struct matchstick *request = request_all(argv);
    int expect = 0;

    draw_sticks(request);
    cr_redirect_stdout();
    expect = empty_line(request, 5);
    cr_expect_eq(expect, -1);
    cr_expect_stdout_eq_str("Error: this line is out of range\n");
    free(request);
}

Test(matchstick, empty_line_work)
{
    char *argv[] = {"./test_run", "4", "4"};
    struct matchstick *request = request_all(argv);
    int expect = 0;

    draw_sticks(request);
    expect = empty_line(request, 1);
    cr_expect_eq(expect, 3);
    free(request);
}

Test(matchstick, display)
{
    char *argv[] = {"./test_run", "4", "4"};
    struct matchstick *request = request_all(argv);

    draw_sticks(request);
    cr_redirect_stdout();
    display_map(request);
    cr_expect_stdout_eq_str("*********\n*   |   *\n*  |||  *\n* ||||| *\n"
    "*|||||||*\n*********\n\n");
    free(request);
}