/*
** EPITECH PROJECT, 2019
** test_my_str_isprintable
** File description:
** Test program
*/

#include <criterion/criterion.h>

int my_str_isprintable(char *str);

Test(my_str_isprintable, test_with_printable)
{
    char str[8] = "bonj69r";

    cr_assert_eq(my_str_isprintable(str), 1);
}

Test(my_str_isprintable, test_with_not)
{
    char str[8] = "bonjour";
    str[3] = 28;

    cr_assert_eq(my_str_isprintable(str), 0);
}
