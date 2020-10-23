/*
** EPITECH PROJECT, 2019
** test_my_str_isalpha
** File description:
** Test program
*/

#include <criterion/criterion.h>

int my_str_isalpha(char *str);

Test(my_str_is_alpha, test_with_full_alpha)
{
    char str[8] = "Bonjour";

    cr_assert_eq(my_str_isalpha(str), 1);
}

Test(my_str_is_alpha, test_noalpha)
{
    char str[8] = "Bon6our";

    cr_assert_eq(my_str_isalpha(str), 0);
}
