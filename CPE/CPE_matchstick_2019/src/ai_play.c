/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** ai_play.c
*/

#include "matchstick.h"

static int my_rand(int a, int b)
{
    return (rand() % (b - a) + a);
}

static void remove_ia_match(int line, int nb, struct matchstick *request)
{
    int i = my_strlen(request->map[0]) - 1;

    while (i >= 0 && nb != 0) {
        if (request->map[line][i] == '|') {
            request->map[line][i] = ' ';
            nb -= 1;
        }
        i -= 1;
    }
}

static void print_ia(int nb, int i)
{
    write(1, "AI removed ", 11);
    my_putnbr(nb, "0123456789");
    write(1, " match(es) from line ", 21);
    my_putnbr(i + 1, "0123456789");
    my_putchar('\n');
}

static void random_stick(struct matchstick *request)
{
    int i = my_rand(0, request->size - 1);
    int length = 0;
    int nb = 0;

    while ((length = empty_line(request, i)) != -1) {
        if (length == 0) {
            i = my_rand(0, request->size);
            continue;
        } if ((check_sticks(request) == 2 && length == 2) || length == 1)
            nb = 1;
        else if (length > request->limit && request->limit != -1)
            nb = my_rand(1, request->limit - 1);
        else
            nb = length - 1;
        if (length == request->limit + 1)
            nb = request->limit;
        remove_ia_match(i, nb, request);
        print_ia(nb, i);
        break;
    }
}

void ai_turn(struct matchstick *request)
{
    if (check_sticks(request) == 0) {
        write(1, "You lost, too bad...\n", 22);
        request->end = 2;
        return;
    }
    write(1, "AI's turn...\n", 13);
    random_stick(request);
    if (check_sticks(request) == 0) {
        display_map(request);
        write(1, "I lost... snif... but I'll get you next time!!\n", 48);
        request->end = 1;
        return;
    }
}