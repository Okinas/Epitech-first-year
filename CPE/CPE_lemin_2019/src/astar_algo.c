/*
** EPITECH PROJECT, 2019
** CPE_lemin_2019
** File description:
** astar_algo.c
*/

#include "struct.h"
#include "my.h"
#include <stddef.h>

static int nbr_way(algo_t *algo, char *end)
{
    algo_t *tmp = algo;

    while (tmp->next != NULL) {
        if (my_strcmp(tmp->next->str, end) == 0)
            return (1);
        tmp = tmp->end;
    }
    return (0);
}

static algo_t *new_way(algo_t *algo, list_t *list)
{
    algo_t *tmp = malloc(sizeof(algo_t));

    if (tmp == NULL)
        return (NULL);
    tmp->next = list;
    tmp->end = algo;
    return (tmp);
}

static algo_t *dump(list_t *tmp, algo_t *algo)
{
    list_t *check;
    list_t *list;
    list_t *temp;

    if (tmp == NULL)
        return (algo);
    check = tmp->next[1];
    list = tmp;
    while (check != NULL) {
        temp = check->prev;
        if (temp != NULL && temp->prev == NULL) {
            temp->prev = check;
            if (!(algo = new_way(algo, temp)))
                return (NULL);
        }
        check->prev = list;
        check = check->next[0];
    }
    return (algo);
}

static int path(algo_t *algo, char *end)
{
    list_t *tmp;
    algo_t *new;
    int nbr = 0;

    while (1) {
        new = malloc(sizeof(algo_t));
        if (new == NULL)
            return (1);
        new->next = NULL;
        new->end = NULL;
        while (algo != NULL) {
            tmp = algo->next;
            new = dump(tmp, new);
            algo = algo->end;
        } if (nbr == 1)
            return (0);
        if (new->next == NULL || new->end == NULL)
            return (1);
        algo = new;
        nbr = (nbr_way(algo, end) == 1) ? 1 : 0;
    }
    return (0);
}

int astar_algorithm(file_t *graphic, char *end)
{
    list_t *tmp = graphic->start;
    int error;
    algo_t *algo = malloc(sizeof(algo_t));

    tmp = graphic->start;
    tmp->prev = NULL;
    if (algo == NULL)
        return (1);
    algo->next = tmp;
    algo->end = NULL;
    error = path(algo, end);
    return (error);
}