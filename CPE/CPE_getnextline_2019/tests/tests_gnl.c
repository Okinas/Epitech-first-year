/*
** EPITECH PROJECT, 2019
** CPE_getnextline_2019
** File description:
** tests_gnl.c
*/

#include <criterion/criterion.h>
#include "get_next_line.h"

char *my_realloc(char *str, char *src, int n);

Test(gnl, gnl_global)
{
    int fd = open("tests/file", O_RDONLY);
    char *str1 = get_next_line(fd);

    cr_assert_str_eq(str1, "Mes sincères salutations");
    free(str1);
    close (fd);
}

Test(gnl, empty_read)
{
    int fd = open("tests/empty_read", O_RDONLY);
    char *str1 = get_next_line(fd);

    cr_assert_null(str1);
    free(str1);
    close(fd);
}