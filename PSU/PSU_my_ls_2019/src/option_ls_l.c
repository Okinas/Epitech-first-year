/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** option_ls_l.c
*/

#include "my_ls.h"

void display_blocks(char *tmp)
{
    struct dirent *dirent = NULL;
    struct stat stats;
    DIR *directory = opendir(tmp);
    int temp = 0;
    char *cat = NULL;
    char *old = NULL;

    while ((dirent = readdir(directory))) {
        cat = my_strcat(tmp, "/");
        old = cat;
        cat = my_strcat(cat, dirent->d_name);
        free(old);
        if (lstat(cat, &stats) == 0)
            (dirent->d_name[0] != '.') ? temp += stats.st_blocks : 0;
        free(cat);
    }
    closedir(directory);
    write(1, "total ", 6);
    my_putnbr(temp / 2, "0123456789");
    my_putchar('\n');
}

void option_ls_l(char *tmp, DIR *directory)
{
    char *str = NULL;
    struct dirent *dirent = readdir(directory);
    struct stat stats;
    struct group *group = NULL;
    struct passwd *password = NULL;

    display_blocks(tmp);
    while (dirent != 0) {
        if (dirent->d_name[0] != '.') {
            str = inspect_file(dirent->d_name, tmp);
            stat(str, &stats);
            group = getgrgid(stats.st_uid);
            password = getpwuid(stats.st_uid);
            access_rights(stats);
            print_all(stats, password, group);
            write(1, dirent->d_name, my_strlen(dirent->d_name));
            my_putchar('\n');
            free(str);
        } dirent = readdir(directory);
    }
}