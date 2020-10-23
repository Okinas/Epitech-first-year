/*
** EPITECH PROJECT, 2019
** tmp
** File description:
** radix_sort.c
*/

#include "pushswap.h"

static void second_part(element_t **l_a, element_t **l_b, int *x, int i)
{
    int tmp = 0;

    while (tmp < x[1]) {
        if (((*l_b)->value >> i & 1) == 1) {
            pa("pa ", l_a, l_b);
            x[1] -= 1;
            x[0] += 1;
        } else {
            *l_b = ra("rb ", *l_b);
            tmp += 1;
        }
    }
}

static void loops(element_t **l_a, element_t **l_b, int *x, int i)
{
    int tmp = 0;

    while (tmp < x[0]) {
        if (((*l_a)->value >> i & 1) == 0) {
            pa("pb ", l_b, l_a);
            x[0] -= 1;
            x[1] += 1;
        } else {
            *l_a = ra("ra ", *l_a);
            tmp += 1;
        }
    }
    second_part(l_a, l_b, x, i);
}

static void second_loop(element_t **l_a, element_t **l_b, int *x)
{
    int i = 0;

    while (i < x[1]) {
        pa("pa ", l_a, l_b);
        x[0] += 1;
        x[1] -= 1;
    }
}

void radix_sort(element_t **l_a, element_t **l_b)
{
    int i = 0;
    int *x = malloc(sizeof(int) * 2);

    if (x == NULL)
        return;
    x[0] = length_element(*l_a);
    x[1] = 0;
    while (i < 31) {
        loops(l_a, l_b, x, i);
        i += 1;
    }
    second_loop(l_a, l_b, x);
    free(x);
    return;
}