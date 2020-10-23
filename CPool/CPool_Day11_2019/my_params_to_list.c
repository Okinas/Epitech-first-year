/*
** EPITECH PROJECT, 2019
** my_params_to_list
** File description:
** Create a new list from the command line args
*/

#include <stddef.h>
#include <stdlib.h>
#include "mylist.h"

int put_in_list(linked_list_t **list, char *data)
{
    linked_list_t *element;

    element = malloc(sizeof(*element));
    if (element == NULL)
        return (1);
    element->data = data;
    element->next = *list;
    *list = element;
    return (0);
}

linked_list_t *my_params_to_list(int ac, char * const *av)
{
    int index = 0;
    linked_list_t *list;

    list = NULL;
    while (index < ac) {
        put_in_list(&list, av[index]);
        index += 1;
    }
    return (list);
}
