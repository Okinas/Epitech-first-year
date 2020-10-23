/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** shell.h
*/

#ifndef SHELL_H_
#define SHELL_H_

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <wait.h>
#include <errno.h>
#include "my.h"

typedef struct env_list {
    char *data;
    struct env_list *next;
    struct env_list *prev;
} env_list_t;

char **convert_in_list(env_list_t *);
char *concat(char *, char *, int);
char **str_to_double_array(char *, char);
int count_list(env_list_t *, env_list_t *);
int check_valid(char *);

void my_error(char *);
void my_shell(char **);
void free_tab(char **);
void segfault_handling(int);
void command_shell(char *, env_list_t *);

char exit_cmd(char **, env_list_t *);
char cd_cmd(char **, env_list_t *);
char env_cmd(char **, env_list_t *);
char setenv_cmd(char **, env_list_t *);
char unsetenv_cmd(char **, env_list_t *);
void my_exec(char **, env_list_t *, char *);

env_list_t *fill_env(char **);
void env_display(env_list_t *);
void env_remove(env_list_t *, char *);
char *search_env(env_list_t *, char *);
env_list_t *env_add(env_list_t *, char *, char *);
env_list_t *env_update(env_list_t *, char *, char *);

#endif /* SHELL_H_ */