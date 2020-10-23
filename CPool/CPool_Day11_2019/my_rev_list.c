/*
** EPITECH PROJECT, 2019
** my_rev_to_list
** File description:
** Create a rev the commands line args
*/

#include <stddef.h>
#include "mylist.h"

void my_rev_list(linked_list_t **begin)
{
    int size = 0;
    char *temp;
    linked_list_t *start = *begin;
    linked_list_t *reverse = *begin;

    while (reverse->next != NULL) {
        reverse = reverse->next;
        size += 1;
    }
    while (size > 0) {
        temp = reverse->data;
        reverse->data = start->data;
        start->data = temp;
        size -= 1;
    }
}
