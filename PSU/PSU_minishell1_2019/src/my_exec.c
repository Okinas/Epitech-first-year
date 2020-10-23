/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** my_exec.c
*/

#include "shell.h"

void exec_error(char *error, char **cmd, char **env_array)
{
    my_putstr(cmd[0]);
    if (my_strlen(error) == 0)
        my_putstr(": Command not found.");
    else
        my_putstr(": Permission denied.");
    my_putchar('\n');
    free_tab(cmd);
    free_tab(env_array);
    exit(1);
}

int test_open(char c, char d, char **cmd)
{
    if (c != ' ') {
        if (cmd[0][0] == c && cmd[0][1] == d && (access(cmd[0], F_OK) != -1))
            return (0);
    }
    else if (c == ' ')
        if (cmd[0][0] == d && (access(cmd[0], F_OK) != -1))
            return (0);
    return (1);
}

int path_access(char **cmd, char **env_array)
{
    if (access(cmd[0], X_OK) == 0) {
        execve(cmd[0], cmd, env_array);
        if (errno == ENOEXEC) {
            my_putstr(cmd[0]);
            my_putstr(": Exec format error. Wrong Architecture.\n");
        }
    }
    return (1);
}

char *exec_recursive(char **path, char **cmd, char **env_array, int i)
{
    char *file = cmd[0];

    if (path_access(cmd, env_array) == 0)
        return ("Permission denied.");
    else if (cmd[0][0] != '/')
        file = concat(path[i++], cmd[0], 1);
    if (file != NULL) {
        execve(file, cmd, env_array);
        free(file);
        exec_recursive(path, cmd, env_array, i);
    }
    return (NULL);
}

void my_exec(char **cmd, env_list_t *my_env, char *path)
{
    char **env_array = NULL;
    char **path_array = NULL;
    char *error = NULL;
    int i = 0;
    int status;
    pid_t pid = fork();

    if (pid == -1)
        my_error("Impossible, error with pid");
    if (pid == 0) {
        env_array = convert_in_list(my_env);
        path_array = str_to_double_array(path, ':');
        error = exec_recursive(path_array, cmd, env_array, i);
        free_tab(path_array);
        exec_error(error, cmd, env_array);
    }
    else if (wait(&status) == -1)
        my_error("Impossible de use wait\n");
    segfault_handling(status);
}