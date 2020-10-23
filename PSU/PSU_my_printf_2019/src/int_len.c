/*
** EPITECH PROJECT, 2019
** Tap
** File description:
** utilities.c
*/

int int_len_u(unsigned long int nb)
{
    int length = 1;
    unsigned long int temp = 10;

    while (nb >= temp) {
        length += 1;
        if (temp > 214748364)
            break;
        temp *= 10;
    }
    return length;
}

int int_len(long int nb)
{
    int length = 1;
    long int temp = 10;

    if (nb < 0)
        nb = -nb;
    while (nb >= temp) {
        length += 1;
        if (temp > 214748364)
            break;
        temp *= 10;
    }
    return length;
}