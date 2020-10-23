/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** env_cmd.c
*/

#include "shell.h"

char *my_cat(char *s1, char *s2)
{
    char *dest = malloc(sizeof(char) * (my_strlen(s1) + my_strlen(s2) + 3));
    int i = 0;
    int j = 0;

    while (s2 && s2[i] != '\0') {
        dest[i] = s2[i];
        i += 1;
    }
    dest[i] = 61;
    i += 1;
    while (s1 && s1[j] != '\0')
        dest[i++] = s1[j++];
    dest[i] = '\0';
    return (dest);
}

int check_exist(char **cmd, env_list_t *env)
{
    env_list_t *tmp = env->next;

    while (tmp != env) {
        if (my_strncmp(cmd[1], tmp->data, my_strlen(cmd[1])) == 0) {
            free(tmp->data),
            tmp->data = my_strdup(my_cat(cmd[2], cmd[1]));
            return (1);
        }
        tmp = tmp->next;
    }
    return (0);
}

char setenv_cmd(char **cmd, env_list_t *my_env)
{
    int i = 0;

    while (cmd[i])
        i += 1;
    if (i > 3)
        my_putstr("setenv: Too many arguments\n");
    else if (cmd[1] != NULL) {
        if (check_valid(cmd[1]) == 0)
            return (0);
        if (check_exist(cmd, my_env) == 0) {
            env_remove(my_env, cmd[1]);
            my_env = env_add(my_env, cmd[2], cmd[1]);
        }
    }
    else
        env_cmd(cmd, my_env);
    return (0);
}

char unsetenv_cmd(char **cmd, env_list_t *my_env)
{
    int i = 1;

    if (cmd[1] != NULL) {
        while (cmd[i] != NULL) {
            env_remove(my_env, cmd[i]);
            i += 1;
        }
    }
    else
        my_putstr("unsetenv: Too few arguments.\n");
    return (0);
}

char env_cmd(char **cmd, env_list_t *my_env)
{
    if (cmd[1] != NULL)
        my_putstr("env: Too many arguments\n");
    else if (my_env != NULL)
        env_display(my_env);
    return (0);
}