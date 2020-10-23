/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** utils.c
*/

#include "shell.h"

char *concat(char *path, char *cmd, int cond)
{
    char *tab = NULL;
    int i = -1;
    int j = 0;

    if (path == NULL || cmd == NULL)
        return (NULL);
    tab = malloc(sizeof(char) * (my_strlen(path) + my_strlen(cmd) + 2));
    if (tab == NULL)
        my_error("Error with malloc");
    while (path[++i] != '\0')
        tab[i] = path[i];
    if (cond == 1)
        tab[i++] = '/';
    if (cond == 2)
        tab[i++] = 61;
    while (cmd[j] != '\0')
        tab[i++] = cmd[j++];
    tab[i] = '\0';
    return (tab);
}

int count_list(env_list_t *tmp, env_list_t *my_env)
{
    int nb = 0;

    while (tmp != my_env) {
        tmp = tmp->next;
        nb += 1;
    }
    return (nb);
}

void free_tab(char **tmp)
{
    int i = 0;

    while (tmp[i] != NULL) {
        free(tmp[i]);
        i += 1;
    }
    free(tmp);
}

int check_valid(char *str)
{
    if (!my_isalpha(str[0])) {
        my_putstr("setenv: Variable name must begin with a letter.\n");
        return (0);
    }
    if (!my_isalphanum(str)) {
        my_putstr("setenv: Variable name must contain alphanumeric "
        "characters.\n");
        return (0);
    }
    return (1);
}

void segfault_handling(int status)
{
    if (WTERMSIG(status) == 11) {
        write(1, "Segmentation fault", 18);
        if (__WCOREDUMP(status))
            write(1, " (core dumped)", 14);
        my_putchar('\n');
    }
    else if (WTERMSIG(status) == SIGFPE) {
        write(1, "Floating exception", 18);
        if (__WCOREDUMP(status))
            write(1, " (core dumped)", 14);
        my_putchar('\n');
    }
}