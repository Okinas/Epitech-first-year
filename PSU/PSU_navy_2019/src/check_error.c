/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** check.c
*/

#include "navy.h"

char *read_file(char *file)
{
    int fd = open(file, O_RDONLY);
    int size = 0;
    char *content = NULL;
    struct stat buffer;

    if (fd <= 0)
        return (NULL);
    stat(file, &buffer);
    content = malloc(sizeof(char) * buffer.st_size + 1);
    if (content == NULL)
        return (NULL);
    size = read(fd, content, buffer.st_size);
    if (size <= 0) {
        free(content);
        return (NULL);
    }
    content[size] = '\0';
    return (content);
}

static int checkfile(int ac, char **av)
{
    char *content = NULL;
    char *file = NULL;

    if (ac == 2)
        file = av[1];
    else
        file = av[2];
    content = read_file(file);
    if (content == NULL || check_content(content))
        return (1);
    return (0);
}

int check_error(int ac, char **av)
{
    if (ac != 2 && ac != 3)
        return (1);
    if (ac == 3 && my_str_isnum(av[1]) == 0)
        return (1);
    if (ac == 3 && my_getnbr(av[1]) <= 0)
        return (1);
    if (checkfile(ac, av))
        return (1);
    return (0);
}