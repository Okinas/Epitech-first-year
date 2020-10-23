/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** get_request.c
*/

#include "matchstick.h"

static void fill_struct(struct matchstick *request, char **av)
{
    request->end = 0;
    request->size = my_getnbr(av[1]);
    request->limit = my_getnbr(av[2]);
    request->map = malloc(sizeof(char *) * request->size);
}

struct matchstick *request_all(char **av)
{
    struct matchstick *request = malloc(sizeof(struct matchstick));
    int i = 0;

    if (request == NULL)
        return (NULL);
    fill_struct(request, av);
    if (request->size < 1 || request->size > 100 || request->limit <= 0)
        return (NULL);
    if (request->map == NULL)
        return (NULL);
    while (i < request->size) {
        request->map[i] = malloc(sizeof(char) * (2 * request->size) + 1);
        if (request->map[i] == NULL)
            return (NULL);
        i += 1;
    }
    return (request);
}