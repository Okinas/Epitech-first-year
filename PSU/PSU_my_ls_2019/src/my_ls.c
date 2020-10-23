/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** my_ls.c
*/

#include "my_ls.h"

void check_permissions(char **folder)
{
    int i = 0;
    DIR *directory;

    while (folder[i]) {
        directory = opendir(folder[i]);
        if (directory == NULL) {
            write(1, "my_ls: cannot access ", 21);
            my_putchar(39);
            write(1, folder[i], my_strlen(folder[i]));
            my_putchar(39);
            write(1, ": ", 2);
            perror("");
        }
        closedir(directory);
        i += 1;
    }
}

void final_check(struct my_ls_t *ls, int i)
{
    if (opendir(ls->folder[ls->cpt + i]) != NULL)
        my_putchar('\n');
    else if (opendir(ls->folder[ls->cpt + i]) == NULL) {
        i += 1;
        if (ls->folder[ls->cpt + i] != NULL)
            final_check(ls, i);
    }
}

void do_ls(struct my_ls_t *ls)
{
    DIR *directory;

    while (ls->folder[ls->cpt]) {
        directory = opendir(ls->folder[ls->cpt]);
        if (directory == NULL) {
            ls->cpt += 1;
            break;
        }
        if (ls->folder[1] && ls->ld != 1) {
            write(1, ls->folder[ls->cpt], my_strlen(ls->folder[ls->cpt]));
            my_putchar('\n');
        }
        if (ls->option == 0)
            simple_ls(directory);
        else
            option_ls(ls, directory);
        if (ls->folder[ls->cpt + 1] != NULL)
            final_check(ls, 1);
        closedir(directory);
        ls->cpt += 1;
    }
}

void my_ls(int ac, char **av)
{
    struct my_ls_t ls;

    struct_fill(&ls, ac, av);
    check_permissions(ls.folder);
    do_ls(&ls);
    free_array(ls.folder);
}