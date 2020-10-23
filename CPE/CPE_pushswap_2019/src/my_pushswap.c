/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** my_pushswap.c
*/

#include "pushswap.h"

static int check_sort(element_t *l_a)
{
    element_t *tmp = l_a;
    element_t *final = l_a;

    if (length_element(l_a) <= 1)
        return (1);
    while (tmp->next->next != final) {
        if (tmp->value > tmp->next->value)
            return (0);
        tmp = tmp->next;
    }
    if (tmp->next->value < tmp->value)
        return (0);
    return (1);
}

static element_t *put_in_list(int argc, char const **argv, int *nbneg)
{
    int to_do;
    element_t *l_a = NULL;

    while (argc >= 2) {
        to_do = my_getnbr(argv[argc - 1], nbneg);
        l_a = put_in_top(l_a, to_do);
        argc -= 1;
    }
    return (l_a);
}

void my_pushswap(int argc, char const **argv)
{
    int nbneg = 0;
    element_t *l_a = put_in_list(argc, argv, &nbneg);
    element_t *l_b = NULL;

    if (check_sort(l_a) != 0) {
        write(1, "\n", 1);
        return;
    }
    if (nbneg == 0)
        radix_sort(&l_a, &l_b);
    else
        quicksort(&l_a, &l_b, length_element(l_a));
    write(1, "rra ra\n", 7);
    free(l_a);
    free(l_b);
}