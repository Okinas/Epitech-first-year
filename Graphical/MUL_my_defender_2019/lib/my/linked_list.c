/*
** EPITECH PROJECT, 2019
** Linked_list
** File description:
** EvalExpr
*/

#include <stdlib.h>
#include <stddef.h>
#include "my.h"

void insert_in_list(list_t **list, char *value)
{
    list_t *element;

    element = malloc(sizeof(list_t));
    element->value = value;
    element->next = *list;
    *list = element;
}

void append_in_list(list_t **list, char *value, int sticks)
{
    list_t *element;
    list_t *temp = *list;

    element = malloc(sizeof(list_t));
    element->value = value;
    element->nb = sticks;
    element->next = NULL;
    if (*list == NULL) {
        *list = element;
    } else {
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = element;
    }
}

void print_list(list_t *list)
{
    while (list) {
        my_putstr(list->value);
        my_putchar('\n');
        list = list->next;
    }
}

void delete_node(list_t **list, int i)
{
    list_t *temp = *list;

    while (i > 0) {
        temp = temp->next;
        i -= 1;
    }
    temp->next = temp->next->next;
}

int get_list_nb(list_t *list, int node)
{
    int i = 1;

    while (i < node && list) {
        i += 1;
        list = list->next;
    }
    return (list->nb);
}
