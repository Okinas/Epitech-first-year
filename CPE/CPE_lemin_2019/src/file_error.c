/*
** EPITECH PROJECT, 2019
** CPE_lemin_2019
** File description:
** file_error.c
*/

#include "my.h"
#include "lemin.h"
#include "struct.h"
#include <stddef.h>
#include <stdbool.h>

bool file_error_2(int nbr, file_t *graphic, char *str)
{
    list_t *tmp;
    char *end;
    way_t *way;

    if (!(tmp = graphic->finish))
        return (false);
    end = tmp->str;
    if (astar_algorithm(graphic, end) != 0)
        return (false);
    if (!(way = follow_way(graphic, str)))
        return (false);
    end_program(way, nbr);
    return (true);
}

int lem_in(void)
{
    file_t *graphic = graphic_create();
    int nbr = 0;
    char *buffer;
    char *temp;
    list_t *tmp;

    if (graphic == NULL)
        return (84);
    while ((buffer = get_next_line(0))) {
        if (nbr == 0 && my_str_isnum(buffer) == 1 &&
        (nbr = my_getnbr(buffer)) && nbr > 0)
            display(nbr);
        else if (!line_check(buffer, graphic) || nbr <= 0)
            return (84);
        free(buffer);
    } if (!(tmp = graphic->start))
        return (84);
    temp = tmp->str;
    if (!(file_error_2(nbr, graphic, temp)))
        return (84);
    return (0);
}