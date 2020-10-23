/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** command_shell.c
*/

#include "shell.h"

static char *path_check(char **tmp, env_list_t *my_env)
{
    char *path = search_env(my_env, "PATH");

    if (path == NULL) {
        my_putstr(tmp[0]);
        my_putstr(": Command not found.\n");
        return (NULL);
    }
    return (path);
}

int compare_cmd(char **cmd)
{
    int i = -1;
    char **build_cmd = malloc(sizeof(char *) * 5);

    if (build_cmd == NULL)
        my_error("Malloc error\n");
    build_cmd[0] = "exit";
    build_cmd[1] = "cd";
    build_cmd[2] = "env";
    build_cmd[3] = "setenv";
    build_cmd[4] = "unsetenv";
    while (++i < 5 && !my_strcmp(cmd[0], build_cmd[i], 0));
    free(build_cmd);
    if (i >= 5)
        return (-1);
    return (i);
}

void do_cmd(int nb, char **str, env_list_t *my_env)
{
    char (*cmd[5])(char **, env_list_t *);

    cmd[0] = exit_cmd;
    cmd[1] = cd_cmd;
    cmd[2] = env_cmd;
    cmd[3] = setenv_cmd;
    cmd[4] = unsetenv_cmd;
    cmd[nb](str, my_env);
}

void command_shell(char *str, env_list_t *my_env)
{
    char **tmp = str_to_double_array(str, ' ');
    char *path = NULL;
    int nb_cmd = 0;

    if (str == NULL || tmp == NULL || tmp[0] == NULL)
        return;
    nb_cmd = compare_cmd(tmp);
    if (nb_cmd >= 5 || nb_cmd < 0) {
        path = path_check(tmp, my_env);
        if (path == NULL) {
            free_tab(tmp);
            return;
        }
        my_exec(tmp, my_env, path);
    }
    else
        do_cmd(nb_cmd, tmp, my_env);
    free_tab(tmp);
}