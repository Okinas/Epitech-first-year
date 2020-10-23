/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** Task05
*/

#include <stddef.h>

int test_lengh(size_t nb)
{
    int nb_final;

    if (nb > 2147483647)
    {
        return (0);
    }
    else {
        nb_final = nb;
        return (nb_final);
    }
}

int last_return (size_t nb, int tiret)
{
    int nb_final;

    if (tiret == 1) {
        nb_final = test_lengh(nb);
        return (-nb_final);
    } else {
        nb_final = test_lengh(nb);
        return (nb_final); } }

int my_getnbr(char const *str)
{
    int cpt = 0;
    size_t nb = 0;
    int started = 0;
    int tiret = 0;

    while (str[cpt] != '\0') {
        if (str[cpt] >= '0' && str[cpt] <= '9') {
            nb = (nb * 10) + (str[cpt] - 48);
            started = 1;
            if (started == 1 && str[cpt - 1] == '-')
            {
                tiret = 1; }
            cpt = cpt + 1;
        } else {
            cpt = cpt + 1;
            if (started == 1) {
                break; } } }
    return (last_return (nb, tiret));
}
