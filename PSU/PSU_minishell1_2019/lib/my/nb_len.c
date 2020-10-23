/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** nb_len.c
*/

int my_nblen(int nb)
{
    int i = 1;

    while (nb > 9) {
        nb /= 10;
        i += 1;
    }
    return (i);
}
