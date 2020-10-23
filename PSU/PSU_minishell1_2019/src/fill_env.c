/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** fill_env.c
*/

#include "shell.h"

env_list_t *rotative_list(char const *line)
{
    env_list_t *node = malloc(sizeof(env_list_t));

    if (node == NULL)
        my_error("Error with malloc\n");
    node->next = node;
    node->prev = node;
    node->data = my_strdup(line);
    return (node);
}

void assign_list(env_list_t **my_env, env_list_t *tmp)
{
    if (*my_env == NULL)
        *my_env = tmp;
    else {
        tmp->prev = (*my_env)->prev;
        tmp->next = (*my_env);
        (*my_env)->prev->next = tmp;
        (*my_env)->prev = tmp;
    }
}

env_list_t *fill_env(char **env)
{
    env_list_t *my_env = NULL;
    env_list_t *tmp;
    int i = 0;

    while (env[i] != NULL) {
        tmp = rotative_list(env[i]);
        if (tmp == NULL)
            my_error("Error with malloc\n");
        assign_list(&my_env, tmp);
        i += 1;
    }
    return (my_env);
}

env_list_t *env_add(env_list_t *env, char *s1, char *s2)
{
    env_list_t *tmp = NULL;
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
    tmp = rotative_list(dest);
    free(dest);
    assign_list(&env, tmp);
    return (env);
}