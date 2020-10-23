/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** option_ls.c
*/

#include "my_ls.h"

void simple_ls(DIR *dir)
{
    struct dirent *dirent;

    while ((dirent = readdir(dir)) != 0) {
        if (dirent->d_name[0] != '.') {
            write(1, dirent->d_name, my_strlen(dirent->d_name));
            my_putchar('\n');
        }
    }
}

void option_ls_d(char *dir)
{
    struct stat stats;
    struct passwd *password;
    struct group *group;

    stat(dir, &stats);
    password = getpwuid(stats.st_uid);
    group = getgrgid(stats.st_gid);
    access_rights(stats);
    print_all(stats, password, group);
    write(1, dir, my_strlen(dir));
}