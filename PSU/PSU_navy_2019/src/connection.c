/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** waiting.c
*/

#include "navy.h"

void callback(int sig)
{
    if (sig == SIGUSR1)
        my_putstr("successfully connected\n\n");
}

static void waiting_for_connection(void)
{
    my_putstr("waiting for enemy connection...\n");
    signal(SIGUSR1, sig_handler);
    signal(SIGUSR2, sig_handler);
    for (int i = 0; i < 32; i++)
        pause();
    s_main.ennemy_pid = s_main.number;
    usleep(5000);
    kill(s_main.ennemy_pid, SIGUSR1);
    my_putstr("\nenemy connected\n\n");
}

static void connecting(void)
{
    usleep(5000);
    send_number(s_main.my_pid);
    signal(SIGUSR1, callback);
    pause();
}

void connection(void)
{
    my_putstr("my_pid: ");
    my_put_nbr(s_main.my_pid);
    my_putchar('\n');
    if (s_main.state == SERVER)
        waiting_for_connection();
    else
        connecting();
}