/*
** EPITECH PROJECT, 2019
** Linked_list
** File description:
** EvalExpr
*/

#include <stdlib.h>
#include <stddef.h>
#include "my.h"

void insert_in_list(linked_list_t **list, char *value)
{
    linked_list_t *element;

    element = malloc(sizeof(linked_list_t));
    element->value = value;
    element->next = *list;
    *list = element;
}

void append_in_list(linked_list_t **list, char *value, int sticks)
{
    linked_list_t *element;
    linked_list_t *temp = *list;

    element = malloc(sizeof(linked_list_t));
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

void print_list(linked_list_t *list)
{
    while (list) {
        my_putstr(list->value);
        my_putchar('\n');
        list = list->next;
    }
}

void delete_node(linked_list_t **list, int i)
{
    linked_list_t *temp = *list;

    while (i > 0) {
        temp = temp->next;
        i -= 1;
    }
    temp->next = temp->next->next;
}

int get_list_nb(linked_list_t *list, int node)
{
    int i = 1;

    while (i < node && list) {
        i += 1;
        list = list->next;
    }
    return (list->nb);
}
