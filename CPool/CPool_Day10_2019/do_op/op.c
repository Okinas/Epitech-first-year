/*
** EPITECH PROJECT, 2019
** op
** File description:
** Make operation for doop
*/

#include "my.h"

int my_add(int av1, int av2)
{
    my_put_nbr(av1 + av2);
}

int my_sub(int av1, int av2)
{
    my_put_nbr(av1 - av2);
}

int my_div(int av1, int av2)
{
    my_put_nbr(av1 / av2);
}

int my_mul(int av1, int av2)
{
    int mult = 1;
    int result = av1;

    while (mult != av2) {
        result += av1;
        mult += 1; }
    my_put_nbr(result);
}

int my_mod(int av1, int av2)
{
    my_put_nbr(av1 % av2);
}
