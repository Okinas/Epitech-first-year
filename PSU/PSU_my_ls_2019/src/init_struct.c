/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** init_struct.c
*/

#include "my_ls.h"

int check_flags(char c)
{
    char *flags = "ldrtR";
    int i = 0;

    while (flags[i] != '\0') {
        if (flags[i] == c)
            return 1;
        i += 1;
    }
    return 0;
}

void fill_option(struct my_ls_t *ls, char c)
{
    if (c == 'l') {
        ls->lr = 1;
        ls->option = 1;
    }
    if (c == 'r') {
        ls->rr = 1;
        ls->option = 1;
    }
    if (c == 'd') {
        ls->ld = 1;
        ls->option = 1;
    }
    if (c == 't') {
        ls->lt = 1;
        ls->option = 1;
    }
    if (c == 'R') {
        ls->l_r = 1;
        ls->option = 1;
    }
}

void struct_option(struct my_ls_t *ls, char *str)
{
    int i = 0;

    if (str[i] == '-')
        i += 1;
    if (check_flags(str[i]) == 0) {
        write(1, "my_ls: invalid option -- '", 26);
        my_putchar(str[i]);
        write(1, "'\n", 2);
        exit(84);
    }
    while (str[i]) {
        fill_option(ls, str[i]);
        i += 1;
    }
}

void fill_folder(struct my_ls_t *ls, char *str)
{
    static int nbr = 0;

    ls->folder[nbr] = my_strdup(str);
    nbr += 1;
    ls->folder[nbr] = NULL;
}

void struct_fill(struct my_ls_t *ls, int ac, char **av)
{
    int i = 1;

    ls->option = 0;
    ls->lr = 0;
    ls->ld = 0;
    ls->lt = 0;
    ls->rr = 0;
    ls->cpt = 0;
    ls->l_r = 0;
    ls->folder = my_str_to_word_array(".", "\n");
    while (i < ac) {
        if (av[i][0] == '-')
            struct_option(ls, av[i]);
        else
            fill_folder(ls, av[i]);
        i += 1;
    }
}