/*
** EPITECH PROJECT, 2019
** test_my_strstr
** File description:
** Test program
*/

#include <criterion/criterion.h>

char *my_strstr(char *str, char *to_find);

Test(my_strstr, test_exists)
{
    char str[10] = "Hello nao";
    char to_find[4] = "nao";

    cr_assert_str_eq(my_strstr(str, to_find), "nao");
}

Test(my_strstr, test_anothers)
{
    char str[14] = "I love my cow";
    char to_find[4] = "cow";

    cr_assert_str_eq(my_strstr(str, to_find), "cow");
}

Test(my_strstr, test_not_exists)
{
    char str[10] = "Hello nao";
    char to_find[5] = "yolo";

    cr_assert_null(my_strstr(str, to_find));
}

Test(my_strstr, test_empty)
{
    char str[10] = "";
    char to_find[4] = "nao";

    cr_assert_null(my_strstr(str, to_find));
}
