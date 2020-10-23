/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** access_right.c
*/

#include "my_ls.h"

void print_rights(struct stat stats)
{
    write(1, S_ISDIR(stats.st_mode) ? "d" : "-", 1);
    write(1, (stats.st_mode & S_IRUSR) ? "r" : "-", 1);
    write(1, (stats.st_mode & S_IWUSR) ? "w" : "-", 1);
    write(1, (stats.st_mode & S_IXUSR) ? "x" : "-", 1);
    write(1, (stats.st_mode & S_IRGRP) ? "r" : "-", 1);
    write(1, (stats.st_mode & S_IWGRP) ? "w" : "-", 1);
}

void other_rights(struct stat stats)
{
    if ((stats.st_mode & __S_ISVTX) && (stats.st_mode & S_IXOTH))
        write(1, "t ", 1);
    else if ((stats.st_mode & __S_ISVTX) && !(stats.st_mode & S_IXOTH))
        write(1, "T ", 2);
    else
        write(1, (stats.st_mode & S_IXOTH) ? "x " : "- ", 2);
}

void access_rights(struct stat stats)
{
    print_rights(stats);
    if ((stats.st_mode & S_ISGID) && !(stats.st_mode & S_IXGRP))
        my_putchar('S');
    else if ((stats.st_mode & S_ISGID) && (stats.st_mode & S_IXGRP))
        my_putchar('s');
    else
        write(1, stats.st_mode ? "x" : "-", 1);
    write(1, (stats.st_mode & S_IROTH) ? "r" : "-", 1);
    write(1, (stats.st_mode & S_IWOTH) ? "w" : "-", 1);
    other_rights(stats);
}