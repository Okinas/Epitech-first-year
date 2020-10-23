/*
** EPITECH PROJECT, 2019
** CPE_lemin_2019
** File description:
** error_handling.c
*/

#include <stdbool.h>
#include "struct.h"
#include <lemin.h>
#include "my.h"

bool display_check(char *str, file_t *graphic, int nbr)
{
    char *buffer;

    my_putstr(str);
    my_putchar('\n');
    if (!(buffer = get_next_line(0)) || !form_check(buffer) ||
    !vertex(graphic, first_arg(buffer, ' '), nbr))
        return (false);
    print_msg(buffer, '#');
    return (true);
}

static bool connection_check(file_t *graphic, char *str)
{
    char *first;
    char *second;
    static int nb;

    if (nb == 0 && ++nb)
        my_putstr("#tunnels\n");
    if (!(first = first_arg(str, '-')) || !(second = second_arg(str, '-'))
    || !check_corner(graphic, first, second) || !check_corner(graphic, second,
    first))
        return (false);
    my_putstr(str);
    my_putchar('\n');
    return (true);
}

static bool room_check(file_t *graphic, char *str)
{
    if (!form_check(str))
        return (false);
    print_msg(str, '#');
    if (!vertex(graphic, first_arg(str, ' '), 0))
        return (false);
    return (true);
}

int line_check(char *str, file_t *graphic)
{
    int nbr = 0;
    int boo = 0;

    if (((!my_strcmp(str, "##start") && ++nbr) ||
    (!my_strcmp(str, "##end") && --nbr)) && boo == 0) {
        if ((nbr == 1 && !display_check("##start", graphic, nbr)) ||
        (nbr == -1 && !display_check("##end", graphic, nbr))) {
            boo = 1;
            return (0);
        }
    }
    if ((count_arg(str, ' ') == 3 && my_str_isnum(str) == 0 &&
    !room_check(graphic, str)) && boo == 0) {
        boo = 1;
        return (0);
    }
    if ((count_arg(str, '-') == 2 && !connection_check(graphic, str)) &&
    boo == 0)
        return (0);
    return (1);
}