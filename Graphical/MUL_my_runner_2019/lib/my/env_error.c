/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** env_error.c
*/

#include "my.h"
#include <stdio.h>
#include <unistd.h>

int check_env(char **env)
{
    int i = 0;

    if (*env == NULL)
        return (1);
    while (env[i] != NULL) {
        if (env[i][0] == 'D' && env[i][1] == 'I' && env[i][2] == 'S' &&
        env[i][3] == 'P' && env[i][4] == 'L' && env[i][5] == 'A'
        && env[i][6] == 'Y' && env[i][7] == '=' && env[i][8] != '\0')
            return (0);
        i += 1;
    }
    write(1, "Missing env\n", 12);
    return (1);
}