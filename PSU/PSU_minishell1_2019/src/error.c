/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** error.c
*/

#include "shell.h"

void my_error(char *str)
{
    write(2, str, my_strlen(str));
    exit(1);
}