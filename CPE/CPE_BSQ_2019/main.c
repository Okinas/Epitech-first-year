/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** mainn.c
*/

#include "bsq.h"

int my_errors(int fd, int lenght, char *buffer)
{
    if (fd < 0)
        return 84;
    if (buffer == NULL)
        return 84;
    if (lenght <= 0)
        return 84;
    return 0;
}

int preparealloc(int fd, char *buffer)
{
    int lenght = 0;
    int size = 0;
    int errors = 0;
    char *save;
    struct stat info;

    stat(buffer, &info);
    size = info.st_size;
    buffer = malloc(sizeof(char) * (size + 1));
    lenght = read(fd, buffer, size);
    buffer[lenght] = '\0';
    save = buffer;
    errors = my_errors(fd, lenght, buffer);
    if (errors == 0)
        errors = bsq(buffer);
    free(save);
    return (errors);
}

int main(int ac, char **argv)
{
    int fd = open(argv[1], O_RDONLY);
    int errors;

    if (ac != 2)
        return (84);
    errors = preparealloc(fd, argv[1]);
    close(fd);
    return (errors);
}