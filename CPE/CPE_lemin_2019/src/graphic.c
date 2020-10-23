/*
** EPITECH PROJECT, 2019
** CPE_lemin_2019
** File description:
** graphic.c
*/

#include "struct.h"
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include "my.h"

file_t *graphic_create(void)
{
    file_t *tmp = malloc(sizeof(file_t));

    if (tmp == NULL)
        return (NULL);
    tmp->length = 0;
    tmp->start = NULL;
    tmp->finish = NULL;
    return (tmp);
}

static void connect_corner(file_t *graphic, list_t *new, char *str)
{
    list_t *tmp = graphic->start;

    while (tmp) {
        if (!my_strcmp(tmp->str, str)) {
            new->prev = tmp;
            break;
        }
        tmp = tmp->next[0];
    }
}

static list_t *element_create(char *str, int nb)
{
    list_t *tmp = malloc(sizeof(list_t));
    int i = 0;

    tmp->next = malloc(sizeof(list_t *) * (nb + 2));
    tmp->prev = malloc(sizeof(list_t));
    if (tmp == NULL || tmp->next == NULL || tmp->prev == NULL)
        return (NULL);
    tmp->str = str;
    while (nb == 0 && i < 2) {
        tmp->next[i] = malloc(sizeof(list_t));
        if (tmp->next[i] == NULL)
            return (NULL);
        tmp->next[i++] = NULL;
    } if (nb == 1) {
        if (!(tmp->next[0] = malloc(sizeof(list_t))))
            return (NULL);
        tmp->next[0] = NULL;
    } tmp->prev = NULL;
    return (tmp);
}

bool check_corner(file_t *graphic, char *name, char *str)
{
    list_t *tmp;
    list_t *temp = element_create(str, 1);

    if (temp == NULL)
        return (false);
    tmp = graphic->start;
    while (tmp) {
        if (!my_strcmp(tmp->str, name)) {
            if (tmp->next[1]) {
                tmp = tmp->next[1];
                while (tmp->next[0] != NULL)
                    tmp = tmp->next[0];
                tmp->next[0] = temp;
            } else
                tmp->next[1] = temp;
            connect_corner(graphic, temp, str);
            break;
        } tmp = tmp->next[0];
    }
    return (true);
}

bool vertex(file_t *graphic, char *str, int nb)
{
    list_t *tmp;
    list_t *temp;

    if (!graphic)
        return (false);
    if (!(temp = element_create(str, 0)))
        return (false);
    tmp = graphic->start;
    if (graphic->length == 0 || nb == 1)
        graphic->start = temp;
    if (nb == -1)
        graphic->finish = temp;
    if (graphic->length != 0) {
        while (tmp->next[0] != NULL)
            tmp = tmp->next[0];
        tmp->next[0] = temp;
    }
    graphic->length += 1;
    return (true);
}