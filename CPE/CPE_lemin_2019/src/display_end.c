/*
** EPITECH PROJECT, 2019
** CPE_lemin_2019
** File description:
** display_end.c
*/

#include "struct.h"
#include "my.h"

static void display_list(ant_t *element)
{
    ant_t *tmp = element;
    int i = 0;

    while (tmp != NULL) {
        i = 0;
        my_putchar('P');
        my_put_nbr(tmp->i);
        my_putchar('-');
        while (tmp->str[i] != '\n' && tmp->str[i] != '\0') {
            write(1, &tmp->str[i], 1);
            i += 1;
        }
        tmp = tmp->next;
        if (tmp != NULL)
            my_putchar(' ');
    }
    my_putchar('\n');
}

static ant_t *add_element(ant_t *ant, char *str, int i)
{
    ant_t *element = malloc(sizeof(ant_t));

    if (element == NULL)
        return (NULL);
    element->str = str;
    element->i = i;
    element->next = ant;
    return (element);
}

static void display_ant(int i, way_t *way)
{
    way_t *tmp = way->next;
    ant_t *element = NULL;

    while (i != 0 && tmp->next != NULL) {
        element = add_element(element, tmp->str, i);
        tmp = tmp->next;
        i -= 1;
    }
    if (element != NULL)
        display_list(element);
}

void end_program(way_t *way, int nbr)
{
    way_t *tmp = way;
    int i = 1;

    my_putstr("#moves\n");
    while (i != nbr) {
        display_ant(i, tmp);
        i += 1;
    }
    while (tmp->next != NULL) {
        if (tmp != NULL && tmp->next != NULL)
            display_ant(i, tmp);
        tmp = tmp->next;
    }
}