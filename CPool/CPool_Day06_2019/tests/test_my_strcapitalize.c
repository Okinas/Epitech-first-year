/*
** EPITECH PROJECT, 2019
** test_my_strcapitalize
** File description:
** Test program
*/

#include <criterion/criterion.h>

char *my_strcapitalize(char *str);

Test(my_strcapitalize, test_full_lowcase)
{
    char str[18] = "hey, how are you?";

    cr_assert_str_eq(my_strcapitalize(str), "Hey, How Are You?");
}
