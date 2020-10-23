/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** my_isalpha.c
*/

int my_isalpha(const char c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        return (1);
    return (0);
}