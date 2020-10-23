/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** command.c
*/

#include "shell.h"

int loop_cmd_check(char **cmd, int nb)
{
    int i = 0;

    while (cmd[1][i] != '\0') {
        if ((cmd[1][i] > '9' && cmd[1][i] <= '~') ||
        (cmd[1][i] >= '!' && cmd[1][i] < 0) || nb > 2) {
            write(1, "Syntax Error\n", 13);
            return (1);
        }
        i += 1;
    }
    return (0);
}

int syntax_error(char **cmd)
{
    int nb = 0;

    while (cmd[nb])
        nb += 1;
    if (cmd[1] != NULL) {
        if (loop_cmd_check(cmd, nb) == 1)
            return (1);
    }
    return (0);
}

char exit_cmd(char **cmd, env_list_t *env)
{
    env_list_t *last;
    int i = 0;

    if (syntax_error(cmd) == 1)
        return (0);
    if (cmd[1] != NULL)
        i = my_getnbr(cmd[1]);
    if (env != NULL) {
        last = env->prev;
        while (last != env) {
            free(env->data);
            env = env->next;
        }
    }
    free_tab(cmd);
    write(1, "exit\n", 5);
    exit(i);
    return (0);
}