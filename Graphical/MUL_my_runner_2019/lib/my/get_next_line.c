/*
** EPITECH PROJECT, 2019
** tmp
** File description:
** get_next_line.c
*/

#include "my.h"
#include <stdlib.h>
#include <unistd.h>

static int begin_of_file(int *fd, int *inc, char *red)
{
    int c_red = 0;

    if (READ_SIZE == 0)
        return (84);
    if (red[*inc] == '\0') {
        c_red = read(*fd, red, READ_SIZE);
        if (c_red == -1)
            return (84);
        red[c_red] = '\0';
        *inc = 0;
    }
    return (0);
}

static int end_of_file(int *fd, int *inc, char *red)
{
    int c_red = 0;

    if (red[*inc] == '\0') {
        c_red = read(*fd, red, READ_SIZE);
        if (c_red < READ_SIZE && c_red > 0)
            red[c_red] = '\n';
        else if (c_red == 0)
            return (84);
        red[c_red + 1] = '\0';
        *inc = 0;
    }
    return (0);
}

static char *my_realloc_out(int *limit, char *out)
{
    char *save = malloc(sizeof(char) * (*limit + 1));
    int i = 0;
    int j = 0;

    while (i != *limit) {
        save[i] = out[i];
        i = i + 1;
    }
    free(out);
    *limit = *limit + 10;
    out = malloc(sizeof(char) * (*limit + 1));
    while (j != i) {
        out[j] = save[j];
        j = j + 1;
    }
    free(save);
    return (out);
}

char *get_next_line(int fd)
{
    int limit = 10;
    char *out = malloc(sizeof(char) * (limit + 1));
    static char red[READ_SIZE + 2];
    static int inc = 0;
    int aba = 0;

    if (begin_of_file(&fd, &inc, red) == 84)
        return (NULL);
    while (red[inc] != '\n') {
        if (aba == limit)
            out = my_realloc_out(&limit, out);
        out[aba] = red[inc];
        aba = aba + 1;
        inc = inc + 1;
        if (end_of_file(&fd, &inc, red) == 84)
            return (NULL);
    }
    out[aba] = '\0';
    inc = inc + 1;
    return (out);
}