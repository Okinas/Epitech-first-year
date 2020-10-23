/*
** EPITECH PROJECT, 2019
** test_my_strncmp
** File description:
** Test program
*/

#include <criterion/criterion.h>

int my_strncmp(char const *s1, char const *s2, int n);

Test(my_strncmp, test_equi)
{
    char s1[] = "jklmn";
    char s2[] = "jklm";

    cr_assert_eq(my_strncmp(s1, s2, 4), 0);
}

Test(my_strncmp, test_most)
{
    char s1[] = "jklmn";
    char s2[] = "jklm";

    cr_assert(my_strncmp(s1, s2, 5) == 110);
}

Test(my_strncmp, test_less)
{
    char s1[] = "jklm";
    char s2[] = "jklmn";

    cr_assert(my_strncmp(s1, s2, 5) == -110);
}
