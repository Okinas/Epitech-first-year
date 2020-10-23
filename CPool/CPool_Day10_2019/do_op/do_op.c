/*
** EPITECH PROJECT, 2019
** do_op
** File description:
** Make operation +, -, *, /, %.
*/

#include <stdlib.h>
#include "my.h"

int my_add(int av1, int av2);

int my_sub(int av1, int av2);

int my_mul(int av1, int av2);

int my_div(int av1, int av2);

int my_mod(int av1, int av2);

int check_operation(char *out)
{
    int index = 0;

    while (out[index] != '\0') {
        if (out[index] == '+')
            return (0);
        if (out[index] == '-')
            return (1);
        if (out[index] == '*')
            return (2);
        if (out[index] == '/')
            return (3);
        if (out[index] == '%')
            return (4);
        index += 1;
    }
    return (5);
}

int check_error(int ac, char **av)
{
    int operation = check_operation(av[2]);
    int ((*out[])(int, int)) = {&my_add, &my_sub, &my_mul, &my_div, &my_mod};

    if (ac != 4)
        return (84);
    if (operation == 3 && my_getnbr(av[3]) == 0) {
        my_putstr("Stop: division by zero");
        my_putchar('\n');
        return (84); }
    if (operation == 4 && my_getnbr(av[3]) == 0) {
        my_putstr("Stop: modulo by zero");
        my_putchar('\n');
        return (84); }
    if (operation == 5) {
        my_putchar('0');
        return (84); }
}

int main(int ac, char **av)
{
    if (ac == 2)
        return (84);
    int value3 = my_getnbr(av[3]);
    int operation = check_operation(av[2]);
    int ((*out[])(int, int)) = {&my_add, &my_sub, &my_mul, &my_div, &my_mod};

    if ((av[1][0] >= 'a' && av[1][0] <= 'z') ||
    (av[1][0] >= 'A' && av[1][0] <= 'Z')) {
        my_put_nbr(value3);
        my_putchar('\n');
        return (0); }
    if (check_error(ac, av) == 84)
        return (84);
    out[operation](my_getnbr(av[1]), my_getnbr(av[3]));
    my_putchar('\n');
    return (0);
}
