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

Test(my_printf_extra_flags_lenght, flags_short_int_d)
{
    short int nb = 32767;

    cr_redirect_stdout();
    my_printf("%hd\n", nb);
    cr_assert_stdout_eq_str("32767\n");
}

Test(my_printf_extra_flags_lenght, flags_short_int_i)
{
    short int nb = -32768;

    cr_redirect_stdout();
    my_printf("%hi\n", nb);
    cr_assert_stdout_eq_str("-32768\n");
}

Test(my_printf_extra_flags_lenght, flags_short_octal)
{
    unsigned short int nb = 12;

    cr_redirect_stdout();
    my_printf("%ho\n", nb);
    cr_assert_stdout_eq_str("14\n");
}

Test(my_print_f, flags_short_binary)
{
    unsigned short int nbr = 65535;

    cr_redirect_stdout();
    my_printf("%hb\n", nbr);
    cr_assert_stdout_eq_str("1111111111111111\n");
}

Test(my_print_f, flags_short_hexa)
{
    unsigned short int nbr = 65535;

    cr_redirect_stdout();
    my_printf("%hx\n", nbr);
    cr_assert_stdout_eq_str("ffff\n");
}

Test(my_print_f, flags_short_hexa_upper)
{
    unsigned short int nbr = 65535;

    cr_redirect_stdout();
    my_printf("%hX\n", nbr);
    cr_assert_stdout_eq_str("FFFF\n");
}

Test(my_printf_extra_flags_lenght, flags_short_short_int_d)
{
    char nb = 127;

    cr_redirect_stdout();
    my_printf("%hhd\n", nb);
    cr_assert_stdout_eq_str("127\n");
}

Test(my_printf_extra_flags_lenght, flags_short_short_int_2_d)
{
    char nb = 2;

    cr_redirect_stdout();
    my_printf("%hhd\n", nb);
    cr_assert_stdout_eq_str("2\n");
}

Test(my_printf_extra_flags_lenght, flags_short_short_int_i)
{
    char nb = -128;

    cr_redirect_stdout();
    my_printf("%hhi\n", nb);
    cr_assert_stdout_eq_str("-128\n");
}

Test(my_printf_extra_flags_lenght, flags_short_short_int_2_i)
{
    char nb = -127;

    cr_redirect_stdout();
    my_printf("%hhi\n", nb);
    cr_assert_stdout_eq_str("-127\n");
}

Test(my_printf_extra_flags_lenght, flags_short_short_octal)
{
    unsigned char nb = 255;

    cr_redirect_stdout();
    my_printf("%hho\n", nb);
    cr_assert_stdout_eq_str("377\n");
}

Test(my_print_f, flags_short_short_binary)
{
    unsigned char nbr = 255;

    cr_redirect_stdout();
    my_printf("%hhb\n", nbr);
    cr_assert_stdout_eq_str("11111111\n");
}

Test(my_print_f, flags_short_short_hexa)
{
    unsigned char nbr = 255;

    cr_redirect_stdout();
    my_printf("%hhx\n", nbr);
    cr_assert_stdout_eq_str("ff\n");
}

Test(my_print_f, flags_short_short_hexa_upper)
{
    unsigned char nbr = 255;

    cr_redirect_stdout();
    my_printf("%hhX\n", nbr);
    cr_assert_stdout_eq_str("FF\n");
}