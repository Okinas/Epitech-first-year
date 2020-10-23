/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** option_ls_t.c
*/

#include "my_ls.h"

void my_print_array(char **tab)
{
    int i = 0;

    while (tab[i]) {
        write(1, tab[i], my_strlen(tab[i]));
        my_putchar('\n');
        i += 1;
    }
}

char **elem_swap(char **tab, int i, int index)
{
    char *swap = my_strdup(tab[i]);

    tab[i] = my_strdup(tab[index]);
    tab[index] = my_strdup(swap);
    free(swap);
    return (tab);
}

char **time_cmp(char **tab, char *dir)
{
    struct stat stats;
    char *s1 = NULL;
    char *s2 = NULL;
    long tmp = 0;
    int y = 0;

    while (tab[y + 1]) {
        s1 = inspect_file(tab[y], dir);
        s2 = inspect_file(tab[y + 1], dir);
        stat(s1, &stats);
        tmp = stats.st_mtime;
        stat(s2, &stats);
        if (tmp < stats.st_mtime) {
            elem_swap(tab, y, y + 1);
            y = 0;
        }
        else
            y += 1;
    }
    return (tab);
}

void option_ls_t(char *dir, DIR *directory)
{
    struct dirent *dirent;
    char **tab;
    char *tags = "\0";

    while ((dirent = readdir(directory)) != 0) {
        if (dirent->d_name[0] != '.') {
            tags = my_strcat(tags, dirent->d_name);
            tags = my_strcat(tags, "\n");
        }
    }
    tab = my_str_to_word_array(tags, "\n");
    tab = time_cmp(tab, dir);
    my_print_array(tab);
}