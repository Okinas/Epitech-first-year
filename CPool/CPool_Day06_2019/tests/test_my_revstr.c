/*
** EPITECH PROJECT, 2019
** test_my_revstr
** File description:
** A test program
*/

#include <criterion/criterion.h>

char *my_revstr(char *str);

Test(my_revstr, copy_five_characters_in_empty_array)
{
    char dest[6] = {0};
    char str[6] = "Hello";

    my_revstr(str);
    cr_assert_str_eq(str, "olleH");
}
