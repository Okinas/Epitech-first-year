/*
** EPITECH PROJECT, 2019
** CPE_getnextline_2019
** File description:
** get_next_line.c
*/

#include "my.h"
#include <unistd.h>
#include <stdlib.h>

int start_read(int fd, int *index, char *save)
{
    int length = 0;

    if (READ_SIZE == 0)
        return (1);
    if (save[*index] == '\0') {
        length = read(fd, save, READ_SIZE);
        if (length <= 0)
            return (1);
        save[length] = '\0';
        *index = 0;
    }
    return (0);
}

int end_read(int fd, int *index, char *save)
{
    int length = 0;

    if (save[*index] == '\0') {
        length = read(fd, save, READ_SIZE);
        if (length > 0 && length < READ_SIZE)
            save[length] = '\n';
        else if (length == 0)
            return (1);
        save[length + 1] = '\0';
        *index = 0;
    }
    return (0);
}

char *my_realloc(char *line, int *limit_read)
{
    char *save = malloc(sizeof(char) * (*limit_read + 1));
    int i = 0;
    int j = 0;

    while (i != *limit_read) {
        save[i] = line[i];
        i += 1;
    }
    free(line);
    *limit_read += 10;
    line = malloc(sizeof(char) * (*limit_read + 1));
    while (j != i) {
        line[j] = save[j];
        j += 1;
    }
    free(save);
    return (line);
}

char *get_next_line(int fd)
{
    static char save[READ_SIZE + 2];
    static int index = 0;
    char *line = malloc(sizeof(char) * (11));
    int limit_read = 10;
    int i = 0;

    if (start_read(fd, &index, save) == 1)
        return (NULL);
    while (save[index] != '\n') {
        if (i == limit_read)
            line = my_realloc(line, &limit_read);
        line[i] = save[index];
        i += 1;
        index += 1;
        if (end_read(fd, &index, save) == 1)
            return (NULL);
    }
    line[i] = '\0';
    index += 1;
    return (line);
}