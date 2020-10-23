/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** main.c
*/

#include "hunter.h"
#include <unistd.h>
#include <stdio.h>

static void help(void)
{
    write(1, "\033[1;33mUSAGE:\n"
    "\033[1;31m    ./my_hunter\n"
    "\033[1;33mDESCRIPTION:\n"
    "\033[1;35m   The Hunter & Fox game starts after launching"
    " the executable, \n"
    "   to start a game simply press the Space key.\n"
    "   The game is arcade-style where your goal is to kill a fox and "
    "get the best\n   possible score.\n"
    "\033[1;33mCONTROLS:\033[0m\n"
    "   \033[1;35mTo kill the fox use the mouse click\n"
    "   To open pause menu press escape\n"
    "   To mute the music press M and for resume it press P\n"
    "\033[1;36mGood luck to you!"
    "\033[0m\n", 460);
}

static int my_error(int ac, char **av, char **env)
{
    if (ac == 2 && my_strcmp("-h", av[1]) == 0) {
        help();
        return (2);
    }
    if (check_env(env) == 1)
        return (84);
    else if (ac > 1) {
        write(1, "\033[1;31mInvalid arguments\n\033[0m", 29);
        return (84);
    }
    return (0);
}

int main(int ac, char **av, char **env)
{
    int error = my_error(ac, av, env);

    if (error == 84)
        return (84);
    else if (error == 2)
        return (0);
    return (begin_game());
}