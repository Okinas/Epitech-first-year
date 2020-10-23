/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** functions_list.c
*/

#include "pushswap.h"

int length_element(element_t *list)
{
    int i = 1;
    element_t *final = list;

    if (list == NULL)
        return (0);
    list = list->next;
    while (list != final) {
        list = list->next;
        i += 1;
    }
    return (i);
}

static element_t *list_create(int value)
{
    element_t *tmp = malloc(sizeof(element_t));

    if (tmp == NULL)
        return (NULL);
    tmp->value = value;
    tmp->next = tmp;
    tmp->prev = tmp;
    return (tmp);
}

element_t *delete_top(element_t *list)
{
    element_t *tmp;

    if (list->next == list)
        tmp = NULL;
    else {
        tmp = list->next;
        list->prev->next = list->next;
        list->next->prev = list->prev;
    }
    free(list);
    return (tmp);
}

element_t *put_in_top(element_t *list, int to_do)
{
    element_t *tmp = malloc(sizeof(element_t));

    if (tmp == NULL)
        return (NULL);
    if (list == NULL) {
        free(tmp);
        return (list_create(to_do));
    }
    tmp->value = to_do;
    tmp->next = list;
    tmp->prev = list->prev;
    list->prev->next = tmp;
    list->prev = tmp;
    return (tmp);
}

long double median_calculate(element_t *l_a, int nb)
{
    int i = 0;
    element_t *tmp = l_a;
    long double median = 0;
    long double nb_long = (long double) nb;

    while (i < nb) {
        median += tmp->value;
        tmp = tmp->next;
        i += 1;
    }
    if (median == 0 || nb == 0)
        return (0);
    return (median / nb_long);
}