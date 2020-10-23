/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** navy.c
*/

#include "navy.h"

static void my_print(void)
{
    print_map(s_main.my_map, "my");
    print_map(s_main.ennemy_map, "enemy's");
}

int end_game(int end)
{
    if (end == 1) {
        my_print();
        my_putstr("I won\n");
        return (0);
    } else if (end == -1) {
        my_print();
        my_putstr("Enemy won\n");
        return (1);
    } else
        return (0);
}

void send_number(int number)
{
    int mask = 1;
    int i = 0;

    while (i < 32) {
        if ((number & mask) > 0)
            kill(s_main.ennemy_pid, SIGUSR2);
        else
            kill(s_main.ennemy_pid, SIGUSR1);
        mask = mask << 1;
        i += 1;
        usleep(800);
    }
}

int check_win(void)
{
    int my_crosses = 0;
    int ennemy_crosses = 0;

    for (int i = 0; s_main.my_map[i]; i++) {
        for (int j = 0; s_main.my_map[i][j]; j++) {
            if (s_main.my_map[i][j] == 'x')
                my_crosses += 1;
            if (s_main.ennemy_map[i][j] == 'x')
                ennemy_crosses += 1;
        }
    }
    if (my_crosses == 14)
        return (-1);
    else if (ennemy_crosses == 14)
        return (1);
    else
        return (0);
}

int navy(void)
{
    int end = 0;

    while (end == 0) {
        if (s_main.turn == false) {
            if (s_main.state == CLIENT)
                my_print();
            if (get_attack())
                return (end_game(2));
        } else {
            usleep(300);
            if (s_main.state == SERVER)
                my_print();
            if (attack()) {
                send_number(99);
                return (end_game(2));
            }
        } end = check_win();
    } return (end_game(end));
}