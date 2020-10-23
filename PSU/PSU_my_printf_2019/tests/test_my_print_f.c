/*
** EPITECH PROJECT, 2019
** Python
** File description:
** criterion tests
*/

#include <criterion/criterion.h>
#include <stdio.h>
#include <criterion/redirect.h>
#include "my.h"

Test(my_print_f, flags_int_d)
{
    int nb = 2147483647;

    cr_redirect_stdout();
    my_printf("%d\n", nb);
    cr_assert_stdout_eq_str("2147483647\n");
}

Test(my_print_f, flags_int_i)
{
    int nb = -2147483648;

    cr_redirect_stdout();
    my_printf("%i\n", nb);
    cr_assert_stdout_eq_str("-2147483648\n");
}

Test(my_print_f, flags_char)
{
    char c = 'A';

    cr_redirect_stdout();
    my_printf("%c\n", c);
    cr_assert_stdout_eq_str("A\n");
}

Test(my_print_f, flags_string)
{
    char *str = "Bonjour marvin ça va ?";

    cr_redirect_stdout();
    my_printf("%s\n", str);
    cr_assert_stdout_eq_str("Bonjour marvin ça va ?\n");
}

Test(my_print_f, flags_empty_string)
{
    char *str = NULL;
    int nb;

    cr_redirect_stdout();
    nb = my_strlen(str);
    cr_assert_eq(nb, -1);
}

Test(my_print_f, flags_unsigned)
{
    unsigned int nbr = 2112454933;

    cr_redirect_stdout();
    my_printf("%u\n", nbr);
    cr_assert_stdout_eq_str("2112454933\n");
}

Test(my_print_f, flags_octal)
{
    unsigned int nb = 12;

    cr_redirect_stdout();
    my_printf("%o\n", nb);
    cr_assert_stdout_eq_str("14\n");
}

Test(my_print_f, flags_unsigned_binary)
{
    unsigned int nbr = 1912277282;

    cr_redirect_stdout();
    my_printf("%b\n", nbr);
    cr_assert_stdout_eq_str("1110001111110110000100100100010\n");
}

Test(my_print_f, flags_unsigned_hexa)
{
    unsigned int nbr = 2147483647;

    cr_redirect_stdout();
    my_printf("%x\n", nbr);
    cr_assert_stdout_eq_str("7fffffff\n");
}

Test(my_print_f, flags_unsigned_hexa_upper)
{
    unsigned int nbr = 2147483647;

    cr_redirect_stdout();
    my_printf("%X\n", nbr);
    cr_assert_stdout_eq_str("7FFFFFFF\n");
}

Test(my_print_f, without_flags_percent)
{

    cr_redirect_stdout();
    my_printf("%%\n");
    cr_assert_stdout_eq_str("%\n");
}

Test(my_print_f, flags_ptradress)
{
    char *temp = "Salut";
    char p[] = {'\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0'};

    sprintf(p, "%p\n", temp);
    cr_redirect_stdout();
    my_printf("%p\n", temp);
    cr_assert_stdout_eq_str(p);
}

Test(my_print_f, flags_string_nonprintable)
{
    char temp[] = {31, 'a', 140, '\0'};

    cr_redirect_stdout();
    my_printf("%S\n", temp);
    cr_assert_stdout_eq_str("\\037a\\000\n");
}

Test(my_print_f, flags_octaspe)
{
    unsigned int nb = 12;

    cr_redirect_stdout();
    my_printf("%#o\n", nb);
    cr_assert_stdout_eq_str("014\n");
}

Test(my_print_f, flags_octalspe_empty)
{
    unsigned int nb = 0;

    cr_redirect_stdout();
    my_printf("%#o\n", nb);
    cr_assert_stdout_eq_str("0\n");
}

Test(my_print_f, flags_hexaspe)
{
    unsigned int nbr = 2147483647;

    cr_redirect_stdout();
    my_printf("%#x\n", nbr);
    cr_assert_stdout_eq_str("0x7fffffff\n");
}

Test(my_print_f, flags_hexaspeu)
{
    unsigned int nbr = 2147483647;

    cr_redirect_stdout();
    my_printf("%#X\n", nbr);
    cr_assert_stdout_eq_str("0X7FFFFFFF\n");
}

Test(my_print_f, flags_hexaspe_empty)
{
    unsigned int nbr = 0;

    cr_redirect_stdout();
    my_printf("%#x\n", nbr);
    cr_assert_stdout_eq_str("0\n");
}

Test(my_print_f, flags_hexaspeu_empty)
{
    unsigned int nbr = 0;

    cr_redirect_stdout();
    my_printf("%#X\n", nbr);
    cr_assert_stdout_eq_str("0\n");
}

Test(my_printf_extra_flags_lenght, flags_q)
{
    unsigned long long int nb = 12;

    cr_redirect_stdout();
    my_printf("%qo\n", nb);
    cr_assert_stdout_eq_str("14\n");
}

Test(my_print_f, precision)
{
    cr_redirect_stdout();
    my_printf("%11i\n", 2147483647);
    cr_assert_stdout_eq_str(" 2147483647\n");
}

Test(my_print_f, plus)
{
    cr_redirect_stdout();
    my_printf("%+i\n", 2147483647);
    cr_assert_stdout_eq_str("+2147483647\n");
}

Test(my_print_f, one_space)
{
    cr_redirect_stdout();
    my_printf("% i\n", 2147483647);
    cr_assert_stdout_eq_str(" 2147483647\n");
}

Test(my_print_f, bad_flag)
{
    cr_redirect_stdout();
    my_printf("%K\n", 2147483647);
    cr_assert_stdout_eq_str("%K\n");
}

Test(my_print_f, without_flags)
{
    cr_redirect_stdout();
    my_printf("Bonjour les coupains %\n");
    cr_assert_stdout_eq_str("Bonjour les coupains %\n");
}