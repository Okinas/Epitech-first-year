/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** signal.c
*/

#include "navy.h"

void sig_handler(int sig)
{
    static int i = 0;

    if (sig == SIGUSR1)
        s_main.number = s_main.number | (0 << i);
    else
        s_main.number = s_main.number | (1 << i);
    i += 1;
}

void did_it_touch(int sig)
{
    if (sig == SIGUSR1)
        s_main.touched = false;
    if (sig == SIGUSR2)
        s_main.touched = true;
}