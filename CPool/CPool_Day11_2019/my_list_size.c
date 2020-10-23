/*
** EPITECH PROJECT, 2019
** my_list_size
** File description:
** Returns the number of element of the list
*/

#include <stddef.h>
#include "mylist.h"

int my_list_size(linked_list_t const *begin)
{
    linked_list_t const *temp = begin;
    int index = 0;

    while (temp != NULL) {
        temp = temp->next;
        index += 1;
    }
    return (index);
}
