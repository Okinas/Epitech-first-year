/*
** EPITECH PROJECT, 2019
** Python
** File description:
** criterion tests
*/

#include <criterion/criterion.h>
#include <stdio.h>
#include <criterion/redirect.h>

int my_printf(char *str, ...);

Test(my_printf_extra_flags_lenght, flags_long_int_d)
{
    long int nb = 2247483648;

    cr_redirect_stdout();
    my_printf("%ld\n", nb);
    cr_assert_stdout_eq_str("2247483648\n");
}

Test(my_printf_extra_flags_lenght, flags_long_int_i)
{
    long int nb = -2247483648;

    cr_redirect_stdout();
    my_printf("%li\n", nb);
    cr_assert_stdout_eq_str("-2247483648\n");
}

Test(my_printf_extra_flags_lenght, flags_long_octal)
{
    unsigned int nb = 12;

    cr_redirect_stdout();
    my_printf("%lo\n", nb);
    cr_assert_stdout_eq_str("14\n");
}

Test(my_print_f, flags_long_binary)
{
    unsigned long int nbr = 1912277282;

    cr_redirect_stdout();
    my_printf("%lb\n", nbr);
    cr_assert_stdout_eq_str("1110001111110110000100100100010\n");
}

Test(my_print_f, flags_long_hexa)
{
    unsigned long int nbr = 2147483647;

    cr_redirect_stdout();
    my_printf("%lx\n", nbr);
    cr_assert_stdout_eq_str("7fffffff\n");
}

Test(my_print_f, flags_long_hexa_upper)
{
    unsigned long int nbr = 2147483647;

    cr_redirect_stdout();
    my_printf("%lX\n", nbr);
    cr_assert_stdout_eq_str("7FFFFFFF\n");
}

Test(my_printf_extra_flags_lenght, flags_long_long_int_d)
{
    long long int nb = 2;

    cr_redirect_stdout();
    my_printf("%lld\n", nb);
    cr_assert_stdout_eq_str("2\n");
}

Test(my_printf_extra_flags_lenght, flags_long_long_int_i)
{
    long long int nb = -2247483648;

    cr_redirect_stdout();
    my_printf("%lli\n", nb);
    cr_assert_stdout_eq_str("-2247483648\n");
}

Test(my_printf_extra_flags_lenght, flags_long_long_octal)
{
    unsigned long long int nb = 12;

    cr_redirect_stdout();
    my_printf("%llo\n", nb);
    cr_assert_stdout_eq_str("14\n");
}

Test(my_print_f, flags_long_long_binary)
{
    unsigned int nbr = 1912277282;

    cr_redirect_stdout();
    my_printf("%llb\n", nbr);
    cr_assert_stdout_eq_str("1110001111110110000100100100010\n");
}

Test(my_print_f, flags_long_long_hexa)
{
    unsigned int nbr = 2147483647;

    cr_redirect_stdout();
    my_printf("%llx\n", nbr);
    cr_assert_stdout_eq_str("7fffffff\n");
}

Test(my_print_f, flags_long_long_hexa_upper)
{
    unsigned int nbr = 2147483647;

    cr_redirect_stdout();
    my_printf("%llX\n", nbr);
    cr_assert_stdout_eq_str("7FFFFFFF\n");
}