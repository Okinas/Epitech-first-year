/*
** EPITECH PROJECT, 2019
** CPool_Day12_2019
** File description:
** test_cat.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

int my_cat(int ac, char **av);

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(cat, good_works, .init = redirect_all_stdout)
{
    int ac = 2;
    char *av[] = {"./cat", "test01"};

    my_cat(ac, av);
    cr_assert_stdout_eq_str("Hello World");
}

Test(cat, not_works, .init = redirect_all_stdout)
{
    int ac = 2;
    char *av[] = {"./cat", "SLT Emmeline :D"};

    my_cat(ac, av);
    cr_assert_stdout_eq_str("cat: SLT Emmeline :D: No such file or directory");
}