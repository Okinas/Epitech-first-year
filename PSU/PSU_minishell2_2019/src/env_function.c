/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** env_function.c
*/

#include "shell.h"

char **convert_in_list(env_list_t *my_env)
{
    env_list_t *tmp = NULL;
    char **array = NULL;
    int i = 0;

    if (my_env->prev->data == NULL)
        return (NULL);
    tmp = my_env->next;
    array = malloc(sizeof(char *) * (count_list(tmp, my_env) + 1));
    if (array == NULL)
        my_error("Error with malloc\n");
    while (tmp != my_env) {
        array[i] = my_strdup(tmp->data);
        tmp = tmp->next;
        i += 1;
    }
    array[i] = '\0';
    return (array);
}

char *search_env(env_list_t *my_env, char *cmd)
{
    env_list_t *tmp = NULL;
    int i = 0;

    if (my_env->prev->data == NULL)
        return (NULL);
    tmp = my_env->next;
    while (tmp != my_env) {
        i = 0;
        while (cmd[i] == tmp->data[i]) {
            i += 1;
            if (tmp->data[i] == 61 && (my_strlen(cmd) == i))
                return (&tmp->data[i + 1]);
        }
        tmp = tmp->next;
    }
    return (NULL);
}

env_list_t *env_update(env_list_t *my_env, char *dir, char *str)
{
    env_list_t *tmp = my_env->next;
    int i = 0;
    int j = 0;

    while (tmp != my_env) {
        i = 0;
        while (tmp->data[i] == str[i])
            i += 1;
        if (tmp->data[i] == 61) {
            i = 0;
            tmp->data = malloc(sizeof(char) * my_strlen(dir) + 2);
            if (tmp->data == NULL)
                my_error("Error with malloc");
            while (dir[j] != '\0')
                tmp->data[i++] = dir[j++];
            tmp->data[i] = '\0';
        }
        tmp = tmp->next;
    }
    return (tmp);
}

void env_remove(env_list_t *my_env, char *cmd)
{
    env_list_t *tmp = my_env->next;

    while (tmp != my_env && !my_strcmp(tmp->data, cmd, 1))
        tmp = tmp->next;
    if (tmp != my_env) {
        tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;
        free(tmp->data);
        free(tmp);
    }
}

void env_display(env_list_t *my_env)
{
    env_list_t *tmp = my_env->next;

    while (tmp != my_env) {
        write(1, tmp->data, my_strlen(tmp->data));
        write(1, "\n", 1);
        tmp = tmp->next;
    }
}