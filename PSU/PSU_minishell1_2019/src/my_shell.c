/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** my_shell.c
*/

#include "shell.h"

void shell_header(void)
{
    int fd = open(".myshell", O_RDONLY);
    char *str = NULL;

    if (fd <= 0)
        write(1, "> ", 2);
    else {
        str = get_next_line(fd);
        if (str == NULL)
            write(1, "> ", 2);
        write(1, str, my_strlen(str));
        free(str);
    }
    close(fd);
}

void shell_sig(int c)
{
    (void)c;
    write(1, "\n", 1);
    shell_header();
}

void my_shell(char **env)
{
    char *str = NULL;
    env_list_t *my_env = fill_env(env);

    shell_header();
    while (1) {
        str = get_next_line(0);
        if (signal(SIGINT, shell_sig) == SIG_ERR)
            write(2, "Error: problem with signal SIGInt\n", 34);
        if (str == NULL) {
            command_shell("exit", my_env);
            break;
        }
        command_shell(str, my_env);
        shell_header();
        free(str);
    }
}