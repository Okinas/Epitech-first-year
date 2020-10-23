/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** cd_cmd.c
*/

#include "shell.h"

static char print_error(char *str, char *cd)
{
    write(2, cd, my_strlen(cd));
    write(2, ": ", 2);
    write(2, str, my_strlen(str));
    write(2, "\n", 1);
    return (0);
}

void env_cd(env_list_t *my_env, char *new)
{
    char *tmp = NULL;
    char *for_free = NULL;

    if (search_env(my_env, new) != NULL) {
        tmp = malloc(sizeof(char *) * 128);
        if (tmp == NULL)
            my_error("Error with malloc");
        getcwd(tmp, 128);
        for_free = concat(new, "=", 0);
        my_env = env_update(my_env, concat(for_free, tmp, 0), new);
        free(for_free);
        free(tmp);
    }
}

char *dir_checker(char *cmd, env_list_t *my_env)
{
    char *dir = NULL;

    if (cmd == NULL || my_strcmp(cmd, " ", 0) || my_strcmp(cmd, "\t", 0)
    || my_strcmp(cmd, "\0", 0) || my_strcmp(cmd, "~", 0))
        dir = search_env(my_env, "HOME");
    else if (my_strcmp(cmd, "-", 0))
        dir = search_env(my_env, "OLDPWD");
    else
        dir = cmd;
    return (dir);
}

void dir_error(char **cmd)
{
    if (cmd[1] == NULL || my_strcmp(cmd[1], " ", 0) ||
    my_strcmp(cmd[1], "\t", 0) || my_strcmp(cmd[1], "\0", 0)
    || my_strcmp(cmd[1], "~", 0)) {
        my_putstr("cd: No home directory\n");
        return;
    }
    if (my_strcmp(cmd[1], "-", 0))
        my_putstr(": No such file or directory.\n");
}

char cd_cmd(char **cmd, env_list_t *my_env)
{
    char *dir = dir_checker(cmd[1], my_env);

    if (dir == NULL) {
        dir_error(cmd);
        return (0);
    }
    if (access(dir, F_OK) == -1)
        return (print_error("No such file or directory.", dir));
    if (access(dir, R_OK) == -1)
        return (print_error("Permission denied.", dir));
    env_cd(my_env, "OLDPWD");
    if (chdir(dir) == -1)
        return (print_error("You cannot change the dir.", dir));
    env_cd(my_env, "PWD");
    return (0);
}
