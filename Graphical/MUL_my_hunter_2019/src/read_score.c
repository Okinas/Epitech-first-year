/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** read_score.c
*/

#include "hunter.h"
#include <stddef.h>
#include <sys/stat.h>

void write_score(t_game_fox *main)
{
    int fd_2 = open("game/score", O_RDWR);

    write(fd_2, change_int_str(main->score), my_nblen(main->score));
    close(fd_2);
}

int read_score(int fd)
{
    int size = 0;
    int length = 0;
    char *filepath = "game/score";
    struct stat info;

    stat(filepath, &info);
    size = info.st_size;
    filepath = malloc(sizeof(char) * (size + 1));
    length = read(fd, filepath, size);
    filepath[length] = '\0';
    return (my_getnbr(filepath));
}