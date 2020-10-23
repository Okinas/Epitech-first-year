/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** bsq.c
*/

#include "bsq.h"
#include <stdio.h>

void print_color(char *buffer);

void replace_maps(char *buffer, int *copy)
{
    int i = 0;

    while (buffer[i] != '\0') {
        if (buffer[i] == '.')
            copy[i] = 1;
        if (buffer[i] == 'o')
            copy[i] = 0;
        else if (buffer[i] == '\n')
            copy[i] = -1;
        i += 1;
    }
    copy[i] = -2;
}

void change_maps(int *copy, int sizebuff, int len_lines)
{
    int i = sizebuff - len_lines - 1;
    int next = 0;
    int next_l = 0;
    int next_ln = 0;

    while (i >= 0) {
        if (copy[i] != -1) {
            next = copy[i + 1];
            next_l = copy[i + len_lines];
            next_ln = copy[i + (len_lines + 1)];
            if (copy[i] >= 1 && next >= 1 && next_l >= 1 && next_ln >= 1)
                copy[i] = get_min(next, next_l, next_ln) + 1;
        } i -= 1;
    }
}

void printable_maps(char *buffer, int size, int index, int len_line)
{
    int i = index;
    int value = size;
    int line_to_print = size;
    int line = 0;
    int col = 0;

    while (line_to_print > 0) {
        while (value > 0) {
            buffer[i + line + col] = 'x';
            value -= 1;
            col += 1;
        }
        col = 0;
        value = size;
        line += len_line;
        line_to_print -= 1;
    }
}

int find_biggest(int *copy)
{
    int i = 0;
    int max = 0;
    int index = 0;

    while (copy[i] != -2) {
        if (copy[i] > max) {
            max = copy[i];
            index = i;
        }
        i += 1;
    }
    return (index);
}

int bsq(char *buffer)
{
    int len_lines = 0;
    int sizebuff = 0;
    int coord = 0;
    int nbr_lines = my_getnbr(buffer);
    int *copy;

    buffer = skip_line(buffer);
    sizebuff = my_strlen(buffer);
    len_lines = len_line(buffer);
    copy = malloc(sizeof(int) * (sizebuff + 1));
    if (check_nbrlines(buffer, nbr_lines) == -1
    || check_lenlines(buffer) == -1)
        return 84;
    replace_maps(buffer, copy);
    change_maps(copy, sizebuff, len_lines);
    coord = find_biggest(copy);
    printable_maps(buffer, copy[coord], coord, len_lines);
    print_color(buffer);
    free(copy);
    return 0;
}
