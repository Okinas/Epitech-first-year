/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** main.c
*/

#include "navy.h"

int help(void)
{
    write(1, "USAGE\n"
    "     ./navy [first_player_pid] navy_positions\n"
    "DESCRIPTION\n"
    "     first_player_pid:  only for the 2nd player.  "
    "pid of the first player.\n"
    "     navy_positions:  file "
    "representing the positions of the ships\n", 206);
    return (0);
}

int main(int ac, char **av)
{
    if (ac == 2 && my_strlen(av[1]) == 2 && my_strncmp(av[1], "-h", 2) == 0)
        return (help());
    if (check_error(ac, av))
        return (84);
    s_main = setup(ac, av);
    if (fill_map())
        return (84);
    connection();
    return (navy());
}