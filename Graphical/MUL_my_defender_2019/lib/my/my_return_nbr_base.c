/*
** EPITECH PROJECT, 2019
** tmp
** File description:
** main.c
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int my_strlen(char *str);

void nbr_base(int nb, char *base, char *result, int *i)
{
    int max = my_strlen(base);

    if (nb >= max) {
        nbr_base(nb / max, base, result, i);
        nbr_base(nb % max, base, result, i);
    }
    else {
        result[*i] = base[nb];
        *i += 1;
    }
}

char *my_return_nbr_base(int nb, char *base)
{
    char *result;
    int len_base = my_strlen(base);
    int i = 0;
    int count = 0;
    int nb_cpy = nb;

    while (nb_cpy >= len_base) {
        nb_cpy /= len_base;
        count += 1;
    }
    count += 1;
    result = malloc(sizeof(char) * (count + 1));
    nbr_base(nb, base, result, &i);
    result[count] = '\0';
    return (result);
}
