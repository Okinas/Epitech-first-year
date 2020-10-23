/*
** EPITECH PROJECT, 2019
** cat
** File description:
** A program for cat function.
*/

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include "../include/my.h"

int argless(void)
{
    int end;
    char buffer[30000];

    while (1)
    {
        end = read(0, buffer, 29999);
        buffer[end] = '\0';
        if (end == 0)
            return (0);
        my_putstr(buffer);
    }
}

int check_error(int index, char **av)
{
    if (errno == 2) {
        my_putstr("cat: ");
        my_putstr(av[index]);
        my_putstr(": No such file or directory");
    }
    if (errno == EACCES) {
        my_putstr("cat: ");
        my_putstr(av[index]);
        my_putstr(": Permission denied");
    }
    if (errno == 21) {
        my_putstr("cat: ");
        my_putstr(av[index]);
        my_putstr(": Is a directory");
    }
    else
        return (0);
}

int my_cat(int ac, char **av)
{
    int fd;
    int temp;
    int index = 1;
    char buffer[30000];

    if (ac == 1)
        argless();
    while (index < ac) {
        fd = open(av[index], O_RDONLY);
        check_error(index, av);
        temp = read(fd, buffer, 29999);
        write (1, buffer, temp);
        close (fd);
        index += 1;
    }
    return (0);
}
