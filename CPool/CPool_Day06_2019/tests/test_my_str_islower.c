/*
** EPITECH PROJECT, 2019
** my_str_islower
** File description:
** Test program
*/

#include <criterion/criterion.h>

int my_str_islower(char *str);

Test(my_str_islower, test_with_lower)
{
    char str[8] = "bonjour";

    cr_assert_eq(my_str_islower(str), 1);
}

Test(my_str_islower, test_with_error)
{
    char str[8] = "boNjOuR";

    cr_assert_eq(my_str_islower(str), 0);
}

Test(my_str_islower, test_with_nothing)
{
    char str[1] = "";

    cr_assert_eq(my_str_islower(str), 1);
}
