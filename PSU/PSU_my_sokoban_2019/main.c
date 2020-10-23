/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** main.c
*/

#include "sokoban.h"

static void help(void)
{
    write(1, "USAGE\n"
    "\t./my_sokoban map\n"
    "DESCRIPTION\n"
    "\tmap file representing the warehouse map, containing '#' for walls,\n"
    "\t\t'P' for the player, 'X' for boxes and 'O' for storage locations.\n"
    , 172);
}

static int my_errors(int fd, char *buffer)
{
    if (fd < 0)
        return 84;
    if (buffer == NULL)
        return 84;
    return 0;
}

static int preparealloc(char *buffer)
{
    int size = 0;
    int lenght = 0;
    int status = 0;
    struct stat info;
    int fd = open(buffer, O_RDONLY);

    stat(buffer, &info);
    size = info.st_size;
    buffer = malloc(sizeof(char) * (size + 1));
    if (my_errors(fd, buffer) == 84)
        return (84);
    lenght = read(fd, buffer, size);
    buffer[lenght] = '\0';
    if (lenght <= 0)
        return (84);
    status = my_sokoban(buffer);
    free(buffer);
    close(fd);
    return (status);
}

int main(int ac, char **argv, char **env)
{
    int errors = check_env(env);

    if (ac > 1 && my_strcmp(argv[1], "-h") == 0) {
        help();
        return (0);
    }
    if (ac != 2 || errors != 0)
        return (84);
    errors = preparealloc(argv[1]);
    return (errors);
}