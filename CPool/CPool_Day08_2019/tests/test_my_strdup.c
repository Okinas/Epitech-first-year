/*
** EPITECH PROJECT, 2019
** test_my_strdup
** File description:
** Test program
*/

#include <stddef.h>
#include <criterion/criterion.h>

char *my_strdup(char const *src);

Test(my_strdup, normal)
{
    char const src[] = "Hello";
    char *rec = my_strdup(src);

    cr_assert_str_eq(rec, src);
}

Test(my_strdup, empty)
{
    char const *src = NULL;
    char *rec = my_strdup(src);

    cr_assert_null(rec);
}
