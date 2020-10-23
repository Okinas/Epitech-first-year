/*
** EPITECH PROJECT, 2019
** tmp
** File description:
** sort.c
*/

#include "pushswap.h"

void pa(char *to_print, element_t **l_a, element_t **l_b)
{
    if (*l_b == NULL)
        return;
    write(1, to_print, my_strlen(to_print));
    *l_a = put_in_top(*l_a, (*l_b)->value);
    *l_b = delete_top(*l_b);
}

element_t *ra(char *to_print, element_t *l_a)
{
    if (l_a == NULL)
        return (NULL);
    write(1, to_print, my_strlen(to_print));
    return (l_a->next);
}

element_t *rra(char *to_print, element_t *l_a)
{
    if (l_a == NULL)
        return (NULL);
    write(1, to_print, my_strlen(to_print));
    return (l_a->prev);
}