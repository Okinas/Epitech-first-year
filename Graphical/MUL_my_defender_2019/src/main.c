/*
** EPITECH PROJECT, 2019
** Tower_Defense
** File description:
** main.c
*/

#include "defense.h"

int help(void)
{
    write(1, "\033[01;33mUSAGE\n"
    "\033[0;32m    ./my_defender\n"
    "\033[01;33mDESCRIPTION\n"
    "\033[0;36m    This game is a Tower Defense, your goal is to protect\n"
    "    the end of the road from the gobelins, to help you in your\n"
    "    quest you can build defense to attack them. When you kill a\n"
    "    mob you will earn some coins to improve the speed of your defense\n\n"
    "\033[1;34m    Good luck !\n", 346);
    return (0);
}

int check_env(char **env)
{
    int is_env = 0;

    for (int i = 0; env[i] != NULL; i += 1) {
        if (my_strncmp("DISPLAY", env[i], 6) == 0)
            is_env = 1;
    }
    return (is_env);
}

int main(int ac, char **av, char **env)
{
    if (ac == 2 && my_strcmp(av[1], "-h") == 0)
        return (help());
    if (check_env(env) == 0)
        return (84);
    return (create_window(1920, 1080));
}