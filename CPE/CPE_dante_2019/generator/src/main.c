/*
** EPITECH PROJECT, 2019
** CPE_dante_2019
** File description:
** main.c
*/

#include "generator.h"

int my_isnum(char *str)
{
    for (int i = 0; str[i]; i++)
    {
        if (str[i] < '0' || str[i] > '9')
            return (0);
    }
    return (1);
}

int check_error(int ac, char **av)
{
    if (ac != 3 && ac != 4)
        return (1);
    if (my_isnum(av[1]) == 0 || my_isnum(av[2]) == 0)
        return (1);
    return (0);
}

gen_t *fill_struct(int ac, char **av)
{
    gen_t *gen = malloc(sizeof(gen_t));

    gen->x = atoi(av[1]);
    gen->y = atoi(av[2]);
    gen->n = 0;
    gen->w = 0;
    if (ac == 3)
        gen->perfect = false;
    else
        gen->perfect = true;
    return (gen);
}

int main(int ac, char **av)
{
    gen_t *gen;

    if (check_error(ac, av))
        return (84);
    gen = fill_struct(ac, av);
    return (generator(gen));
}