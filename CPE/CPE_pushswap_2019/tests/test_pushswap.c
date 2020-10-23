/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** test_pushswap.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/pushswap.h"

Test(pushswap, functionnal)
{
    char const *argv[] = {"./test_run", "9", "8", "7", "6", "5"};

    cr_redirect_stdout();
    my_pushswap(6, argv);
    cr_assert_stdout_eq_str("ra pb ra pb ra rb rb pb ra pb rb rb pa rb ra "
    "ra pa rb rb pb pb pb rb rb rb pa pa pb pb rb rb rb rb rb rb rb rb rb rb "
    "rb rb rb rb rb rb rb rb rb rb rb rb rb rb rb rb rb rb rb rb rb rb rb rb "
    "rb rb rb rb rb rb rb rb rb rb rb rb rb rb rb rb rb rb rb rb rb rb rb rb "
    "rb rb rb rb rb rb rb rb rb rb rb rb rb rb rb rb rb rb rb rb rb rb rb rb "
    "rb rb rb rb rb rb rb rb rb rb rb rb rb rb rb rb rb rb rb rb rb rb rb rb "
    "rb rb rb rb rb rb rb rb rb rb rb rb rb rb rb rb rb rb rb rb rb rb rb rb "
    "rb rb rb rb rb pa pa pa pa pa rra ra\n");
}

Test(pushswap, already_sorted)
{
    char const *argv[] = {"./test_run", "8", "9"};

    cr_redirect_stdout();
    my_pushswap(3, argv);
    cr_assert_stdout_eq_str("\n");
}

Test(pushswap, one_number)
{
    char const *argv[] = {"./test_run", "8"};

    cr_redirect_stdout();
    my_pushswap(2, argv);
    cr_assert_stdout_eq_str("\n");
}

Test(pushswap, negative_nbr)
{
    char const *argv[] = {"./test_run", "-8", "-9"};

    cr_redirect_stdout();
    my_pushswap(3, argv);
    cr_assert_stdout_eq_str("ra pb rra pa ra rra rra ra\n");
}