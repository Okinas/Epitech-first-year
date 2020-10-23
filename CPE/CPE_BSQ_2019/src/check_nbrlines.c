/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** check_nbrlines.c
*/

#include "bsq.h"

int check_lenlines(char *buffer)
{
    int i = 0;
    int lens = 0;
    int len_lines = 0;

    while (buffer[len_lines] != '\n')
        len_lines += 1;
    while (buffer[i] != '\0') {
        while (buffer[i] != '\n') {
            lens += 1;
            i += 1;
        }
        if (lens != len_lines)
            return -1;
        lens = 0;
        i += 1;
    }
    return 0;
}

int check_nbrlines(char *buffer, int number)
{
    int i = 0;
    int value = 0;

    while (buffer[i] != '\0') {
        if (buffer[i] == '\n')
            value += 1;
        i += 1;
    }
    if (number == value)
        return value;
    else
        return -1;
}