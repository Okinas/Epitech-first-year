/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** quicksort.c
*/

#include "pushswap.h"

static void reverse_a(element_t **l_a, int nb)
{
    int tmp = 0;

    while (tmp < nb) {
        *l_a = rra("rra ", *l_a);
        tmp += 1;
    }
}

static void rotate_a(element_t **l_a, int nb)
{
    int tmp = 0;

    while (tmp < nb) {
        *l_a = ra("ra ", *l_a);
        tmp += 1;
    }
}

static void push_a(element_t **l_a, element_t **l_b, int nb)
{
    int tmp = 0;

    while (tmp < nb) {
        pa("pa ", l_a, l_b);
        tmp += 1;
    }
}

static int push_b(element_t **l_a, element_t **l_b, int nb)
{
    int i = 0;
    int tmp = 0;
    long double l_a_value;
    long double median = median_calculate(*l_a, nb);

    while (i < nb) {
        l_a_value = (long double) (*l_a)->value;
        if (*l_a != NULL && l_a_value <= median) {
            pa("pb ", l_b, l_a);
            tmp += 1;
        }
        else
            *l_a = ra("ra ", *l_a);
        i += 1;
    }
    return (tmp);
}

void quicksort(element_t **l_a, element_t **l_b, int nb)
{
    int tmp;

    if (nb <= 1)
        return;
    tmp = push_b(l_a, l_b, nb);
    reverse_a(l_a, nb - tmp);
    push_a(l_a, l_b, tmp);
    if (tmp == nb || tmp == 0)
        return;
    quicksort(l_a, l_b, tmp);
    rotate_a(l_a, tmp);
    quicksort(l_a, l_b, nb - tmp);
    reverse_a(l_a, tmp);
}