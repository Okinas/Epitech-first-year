/*
** EPITECH PROJECT, 2019
** Python
** File description:
** criterion tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "bsq.h"

Test(bsq, functional)
{
    char str[] = "9\n"
    "...........................\n"
    "....o......................\n"
    "............o..............\n"
    "...........................\n"
    "....o......................\n"
    "..............o............\n"
    "...........................\n"
    "......o..............o.....\n"
    "..o.......o................\n";

    cr_redirect_stdout();
    bsq(str);
    cr_assert_stdout_eq_str(".....xxxxxxx...............\n"
    "....oxxxxxxx...............\n"
    ".....xxxxxxxo..............\n"
    ".....xxxxxxx...............\n"
    "....oxxxxxxx...............\n"
    ".....xxxxxxx..o............\n"
    ".....xxxxxxx...............\n"
    "......o..............o.....\n"
    "..o.......o................\n");
}

Test(bsq, bsq_lens_lines_diff)
{
    char str[] = "3\n"
    ".....o\n"
    ".......\n"
    "...ooo\n";

    cr_assert_eq(bsq(str), 84);
}

Test(bsq, bsq_nbr_lines_diff)
{
    char str[] = "4\n"
    ".....o\n"
    "......\n"
    "...ooo\n";

    cr_assert_eq(bsq(str), 84);
}