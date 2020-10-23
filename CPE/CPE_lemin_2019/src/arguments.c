/*
** EPITECH PROJECT, 2019
** CPE_lemin_2019
** File description:
** arguments.c
*/

#include <stddef.h>
#include <stdlib.h>

char *first_arg(char *str, char c)
{
    char *tmp = NULL;
    int i = 0;
    int nbr = 0;

    while (str[nbr] && str[nbr] != c)
        ++nbr;
    tmp = malloc(sizeof(char) * (nbr + 1));
    if (tmp == NULL)
        return (NULL);
    while (str[i] != c) {
        tmp[i] = str[i];
        i += 1;
    }
    tmp[i] = '\0';
    return (tmp);
}

char *second_arg(char *str, char c)
{
    char *temp = NULL;
    int i = 0;
    int nbr = 0;
    int tmp = 0;

    while (str[i] != c)
        ++i;
    tmp = ++i;
    while (str[i++])
        ++nbr;
    temp = malloc(sizeof(char) * (nbr + 1));
    if (temp == NULL)
        return (NULL);
    nbr = 0;
    while (str[tmp])
        temp[nbr++] = str[tmp++];
    temp[nbr] = '\0';
    return (temp);
}