/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** function.c
*/

#include "bsq.h"
#include "my.h"

int len_line(char *buffer)
{
    int i = 0;

    while (buffer[i] != '\n')
        i += 1;
    return (i + 1);
}

int get_min(int a, int b, int c)
{
    int value = 1;

    if (a <= b && a <= c)
        value = a;
    if (b <= a && b <= c)
        value = b;
    if (c <= a && c <= b)
        value = c;
    return value;
}

char *skip_line(char *buffer)
{
    int i = 0;

    while (buffer[i] != '\n')
        buffer += 1;
    return (buffer + 1);
}