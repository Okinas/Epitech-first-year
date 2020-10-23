/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** attack.c
*/

#include "navy.h"

int pos_to_int(char *pos)
{
    int nb = 0;

    nb = (pos[0] - 'A') * 10;
    nb += pos[1] - '0';
    return (nb);
}

char *int_to_pos(int nb)
{
    char *pos = malloc(sizeof(char) * 3);

    if (nb == 99 || pos == NULL)
        return (NULL);
    pos[0] = s_main.number / 10 + 'A';
    pos[1] = s_main.number % 10 + '0';
    pos[2] = '\0';
    my_putstr(pos);
    usleep(100);
    return (pos);
}

char *get_hit(void)
{
    char *pos = NULL;

    my_putstr("attack: ");
    pos = get_next_line(0);
    if (check_pos(pos)) {
        my_putstr("wrong position\n");
        free(pos);
        return (get_hit());
    }
    return (pos);
}

int attack(void)
{
    char *pos = get_hit();

    if (pos == NULL)
        return (1);
    usleep(5000);
    send_number(pos_to_int(pos));
    signal(SIGUSR1, did_it_touch);
    signal(SIGUSR2, did_it_touch);
    pause();
    my_putstr(pos);
    if (s_main.touched == true) {
        my_putstr(": hit\n\n");
        hit_map(pos_to_int(pos), 'x', s_main.ennemy_map);
    } else {
        my_putstr(": missed\n\n");
        hit_map(pos_to_int(pos), 'o', s_main.ennemy_map);
    }
    s_main.turn = false;
    free(pos);
    return (0);
}

int get_attack(void)
{
    char *pos = NULL;

    s_main.number = 0;
    my_putstr("waiting for enemy's attack...\n");
    signal(SIGUSR1, sig_handler);
    signal(SIGUSR2, sig_handler);
    for (int i = 0; i < 32; i++)
        pause();
    pos = int_to_pos(s_main.number);
    if (pos == NULL)
        return (1);
    usleep(5000);
    if (check_hit(s_main.number)) {
        kill(s_main.ennemy_pid, SIGUSR2);
        my_putstr(": hit\n\n");
    } else {
        kill(s_main.ennemy_pid, SIGUSR1);
        my_putstr(": missed\n\n");
    } s_main.turn = true;
    free(pos);
    return (0);
}