/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** tests_matchsticks.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "matchstick.h"

Test(matchstick, match_error_zero)
{
    struct matchstick *request = malloc(sizeof(struct matchstick));
    int match = 0;
    int expect = 0;

    request->limit = 4;
    cr_redirect_stdout();
    expect = match_error(request, match);
    cr_expect_eq(expect, 0);
    cr_expect_stdout_eq_str("Error: you have to remove at least one match\n");
    free(request);
}

Test(matchstick, match_error_superior_than_limit)
{
    struct matchstick *request = malloc(sizeof(struct matchstick));
    int match = 5;
    int expect = 0;

    request->limit = 4;
    cr_redirect_stdout();
    expect = match_error(request, match);
    cr_expect_eq(expect, 0);
    cr_expect_stdout_eq_str("Error: you cannot remove more than "
    "4 matches per turn\n");
    free(request);
}

Test(matchstick, match_error_negative)
{
    struct matchstick *request = malloc(sizeof(struct matchstick));
    int match = -1;
    int expect = 0;

    request->limit = 4;
    cr_redirect_stdout();
    expect = match_error(request, match);
    cr_expect_eq(expect, 0);
    cr_expect_stdout_eq_str("Error: invalid input (positive "
    "number expected)\n");
    free(request);
}

Test(matchstick, match_error_no_error)
{
    struct matchstick *request = malloc(sizeof(struct matchstick));
    int match = 2;

    request->limit = 4;
    cr_expect_eq(match_error(request, match), 1);
    free(request);
}

Test(matchstick, error_line_out)
{
    char *argv[] = {"./test_run", "4", "4"};
    struct matchstick *request = request_all(argv);
    int expect = 0;

    draw_sticks(request);
    cr_redirect_stdout();
    expect = line_error(10, request);
    cr_expect_eq(expect, 0);
    cr_expect_stdout_eq_str("Error: this line is out of range\n");
    free(request);
}

Test(matchstick, error_line_negative_nbr)
{
    char *argv[] = {"./test_run", "4", "4"};
    struct matchstick *request = request_all(argv);
    int expect = 0;

    draw_sticks(request);
    cr_redirect_stdout();
    expect = line_error(-1, request);
    cr_expect_eq(expect, 0);
    cr_expect_stdout_eq_str("Error: invalid input (positive number expected)"
    "\n");
    free(request);
}

Test(matchstick, error_line_work_case)
{
    char *argv[] = {"./test_run", "4", "4"};
    struct matchstick *request = request_all(argv);
    int expect = 0;

    draw_sticks(request);
    expect = line_error(4, request);
    cr_expect_eq(expect, 1);
    free(request);
}

Test(matchstick, match_remove_work)
{
    char *argv[] = {"./test_run", "4", "4"};
    struct matchstick *request = request_all(argv);
    int expect = 0;

    draw_sticks(request);
    cr_redirect_stdout();
    expect = match_remove(request, 1, 1);
    cr_expect_eq(expect, 1);
    cr_expect_stdout_eq_str("Player removed 1 match(es) from line 2\n");
    free(request);
}