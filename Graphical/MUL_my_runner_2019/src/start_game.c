/*
** EPITECH PROJECT, 2019
** tmp
** File description:
** start_game.c
*/

#include "runner.h"

static void print_help(void)
{
    write(1, "Usage:\n", 7);
    write(1, "./my_runner [map]\n", 18);
    write(1, "Description:\n", 13);
    write(1, "Your goal is to make finish a level with a maximum "
    "of life\n", 59);
    write(1, "In infinite mode you have to make the highest score you can "
    "do\n", 63);
    write(1, "Controls:\n", 10);
    write(1, "Use ESCAPE for Pause Menu\n", 26);
    write(1, "Use SPACE for Jump\n", 20);
}

int start_game(char **av)
{
    if (av[1][0] == '-' && av[1][1] == 'h') {
        print_help();
        return (0);
    }
    else
        return (0);
}