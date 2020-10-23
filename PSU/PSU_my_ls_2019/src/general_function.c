/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** options_ls.c
*/

#include "my_ls.h"

void free_array(char **tab)
{
    int i = 0;

    while (tab[i] != NULL) {
        free(tab[i]);
        i += 1;
    }
    free(tab);
}

void print_all(struct stat stats, struct passwd *password, struct group *group)
{
    my_putnbr(stats.st_nlink, "0123456789");
    my_putchar(' ');
    write(1, password->pw_name, my_strlen(password->pw_name));
    my_putchar(' ');
    write(1, group->gr_name, my_strlen(group->gr_name));
    my_putchar(' ');
    my_putnbr(stats.st_size, "0123456789");
    my_putchar(' ');
    write(1, (ctime(&stats.st_mtime) + 4),
    (my_strlen(ctime(&stats.st_mtime)) - 13));
    my_putchar(' ');
}

char *inspect_file(char *file, char *list)
{
    char *str = my_strdup(list);
    char *old = str;

    if (my_strcmp(str, ".") == 0) {
        str = my_strcat(str, "/");
        free(old);
        old = str;
        str = my_strcat(str, file);
        free(old);
        return (str);
    }
    str = my_strcat(str, "/");
    str = my_strcat(str, file);
    return (str);
}