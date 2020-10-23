/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** main.c
*/

#include "shell.h"

int main(int ac __attribute__((unused)),
char **av __attribute__((unused)), char **env)
{
    if (env[0] == NULL)
        env[0] = NULL;
    my_shell(env);
    return (0);
}