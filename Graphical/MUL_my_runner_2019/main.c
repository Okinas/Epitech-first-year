/*
** EPITECH PROJECT, 2019
** tmp
** File description:
** main.c
*/

#include "runner.h"

static void print_error(void)
{
    write(1, "Not enough args\n", 16);
}

int main(int ac, char **av, char **env)
{
    int error = check_env(env);

    if (ac != 2) {
        print_error();
        return (84);
    }
    if (error == 0)
        error = start_game(av);
    return (error);
}