/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** setup.c
*/

#include "navy.h"

t_main setup(int ac, char **av)
{
    if (ac == 2) {
        s_main.state = SERVER;
        s_main.ennemy_pid = 0;
        s_main.turn = true;
    }
    else {
        s_main.state = CLIENT;
        s_main.ennemy_pid = my_getnbr(av[1]);
        s_main.turn = false;
    }
    s_main.my_pid = getpid();
    s_main.file = av[ac - 1];
    s_main.number = 0;
    s_main.touched = false;
    return (s_main);
}