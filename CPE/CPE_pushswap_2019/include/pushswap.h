/*
** EPITECH PROJECT, 2019
** tmp
** File description:
** pushswap.h
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"

#ifndef PUSHSWAP_H_
#define PUSHSWAP_H_

typedef struct element {
    int value;
    struct element *next;
    struct element *prev;
} element_t;

void my_pushswap(int argc, char const **argv);
int length_element(element_t *list);

element_t *put_in_top(element_t *l_a, int to_do);
element_t *delete_top(element_t *list);
void pa(char *to_print, element_t **l_a, element_t **l_b);
element_t *ra(char *to_print, element_t *l_a);
element_t *rra(char *to_print, element_t *l_a);
void radix_sort(element_t **l_a, element_t **l_b);

long double median_calculate(element_t *l_a, int nb);
void quicksort(element_t **l_a, element_t **l_b, int nb);

#endif /* PUSHSWAP_H_ */