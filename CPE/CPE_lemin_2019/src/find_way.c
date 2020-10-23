/*
** EPITECH PROJECT, 2019
** CPE_lemin_2019
** File description:
** find_way.c
*/

#include "struct.h"
#include "my.h"
#include <stddef.h>

static way_t *add_begin(way_t *way, char *str)
{
    way_t *tmp = malloc(sizeof(way_t));

    if (tmp == NULL)
        return (NULL);
    tmp->str = str;
    tmp->next = way;
    return (tmp);
}

static way_t *get_path(list_t *graphic, way_t *way, char *str)
{
    list_t *tmp = graphic;

    while (tmp != NULL) {
        tmp = tmp->prev;
        if (tmp == NULL)
            return (NULL);
        way = add_begin(way, tmp->str);
        if (way == NULL)
            return (NULL);
        if (my_strcmp(tmp->str, str) == 0)
            break;
        tmp = tmp->prev;
    }
    return (way);
}

way_t *follow_way(file_t *finish, char *str)
{
    list_t *graphic = finish->finish;
    way_t *way = malloc(sizeof(way_t));

    if (way == NULL)
        return (NULL);
    way->str = graphic->str;
    way->next = NULL;
    way = get_path(graphic, way, str);
    if (way == NULL)
        return (NULL);
    return (way);
}