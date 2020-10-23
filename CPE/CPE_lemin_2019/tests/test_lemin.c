/*
** EPITECH PROJECT, 2019
** CPE_lemin_2019
** File description:
** test_lemin.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <unistd.h>
#include "lemin.h"
#include <stdio.h>

// * Tools testing * \\

bool form_check(char *str);
void display(int nbr);
void print_msg(char *str, char c);
int dprintf(int fd, const char *format, ...);
int lem_in(void);
bool file_error_2(int nbr, file_t *graphic, char *str);
bool display_check(char *str, file_t *graphic, int nbr);
// * Error handling *\\

Test(tools, form_check_false)
{
    cr_assert_eq(form_check("Test 2 spaces"), false);
}

Test(tools, form_check_true)
{
    cr_assert_eq(form_check("4 5 3 2 1 5"), true);
}

Test(tools, display)
{
    cr_redirect_stdout();
    display(3);
    cr_assert_stdout_eq_str("#number_of_ants\n3\n#rooms\n");
}

Test(tools, print_msg)
{
    cr_redirect_stdout();
    print_msg("Number of ants#", '#');
    cr_assert_stdout_eq_str("Number of ants\n");
}

Test(main, file_error_0)
{
    cr_redirect_stdout();
    cr_redirect_stdin();
    freopen("./bonus/file", "r", stdin);
    cr_assert_eq(lem_in(), 0);
}