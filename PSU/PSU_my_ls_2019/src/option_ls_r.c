/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** option_ls_r.c
*/

#include "my_ls.h"

int my_strlen_array(char *array)
{
    int i = 0;

    while (array[i])
        i += 1;
    return (i);
}

void simple_ls_for_rcaps(char *dir)
{
    DIR *tmp = opendir(dir);

    simple_ls(tmp);
    closedir(tmp);
    my_putchar('\n');
}

void option_ls_rcaps(char *dir, struct my_ls_t *ls)
{
    DIR *directory = opendir(dir);
    struct dirent *dirent = NULL;
    struct stat stats;
    char *str = NULL;
    char *old = str;

    simple_ls_for_rcaps(dir);
    while ((dirent = readdir(directory)) != 0) {
        str = my_strcat(dir, "/");
        old = str;
        str = my_strcat(str, dirent->d_name);
        free(old);
        stat(str, &stats);
        if (dirent->d_name[0] != '.' && S_ISDIR(stats.st_mode)) {
            write(1, str, my_strlen(str));
            write(1, ":\n", 2);
            option_ls_rcaps(str, ls);
        }
    }
    closedir(directory);
}

void option_ls_rr(char *dir, struct my_ls_t *ls)
{
    DIR *directory = opendir(dir);
    struct dirent *dirent = NULL;
    struct stat stats;
    char *str = NULL;

    option_ls_l(dir, opendir(dir));
    my_putchar('\n');
    while ((dirent = readdir(directory)) != 0) {
        str = my_strcat(dir, "/");
        str = my_strcat(str, dirent->d_name);
        stat(str, &stats);
        if (dirent->d_name[0] != '.' && S_ISDIR(stats.st_mode)) {
            write(1, str, my_strlen(str));
            write(1, ":\n", 2);
            option_ls_rr(str, ls);
        }
    }
}

void option_ls_rmin(char *dir)
{
    struct dirent *dirent = NULL;
    char **array = my_str_to_word_array("azertyu\n", "\n");
    int i = 0;
    DIR *directory = opendir(dir);

    while ((dirent = readdir(directory)) != 0) {
        if (dirent->d_name[0] != '.') {
            array[i] = my_strdup(dirent->d_name);
            i += 1;
        }
    }
    i -= 1;
    while (i >= 0) {
        write(1, array[i], my_strlen_array(array[i]));
        my_putchar('\n');
        i -= 1;
    }
    free_array(array);
    free(directory);
}