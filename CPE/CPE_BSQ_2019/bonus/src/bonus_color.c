/*
** EPITECH PROJECT, 2019
** src
** File description:
** bonus_color.c
*/

#include <stdio.h>
#include <unistd.h>

void yellow(void)
{
    write(1, "\033[1;33m", 7);
}

void dark_red(void)
{
    write(1, "\033[1;31m", 7);
}

void green(void)
{
    write(1, "\033[0;32m", 7);
}

void reset(void)
{
    write(1, "\033[0m", 7);
}

void print_color(char *buffer)
{
    int i = 0;

    while (buffer[i] != '\0') {
        if (buffer[i] == 'x') {
            yellow();
            write(1, &buffer[i], 1);
        }
        else if (buffer[i] == 'o') {
            dark_red();
            write(1, &buffer[i], 1);
        }
        else {
            green();
            write(1, &buffer[i], 1);
        }
        reset();
        i += 1;
    }
}