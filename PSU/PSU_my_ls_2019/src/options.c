/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** function.c
*/

#include "my_ls.h"

void other_options(struct my_ls_t *ls)
{
    if (ls->ld == 1 && ls->rr == 0 && ls->lt == 0 && ls->l_r == 0 &&
    ls->lr == 0) {
        write(1, ls->folder[ls->cpt], my_strlen(ls->folder[ls->cpt]));
        if (ls->folder[ls->cpt + 1] == NULL)
            my_putchar('\n');
    }
    if (ls->lr == 1 && ls->ld == 1 && ls->rr == 0 && ls->l_r == 0 &&
    ls->lt == 0) {
        option_ls_d(ls->folder[ls->cpt]);
        if (ls->folder[ls->cpt + 1] == NULL)
            my_putchar('\n');
    }
    if (ls->lr == 1 && ls->l_r == 1 && ls->rr == 0 && ls->ld == 0 &&
    ls->lt == 0) {
        write(1, ls->folder[ls->cpt], my_strlen(ls->folder[ls->cpt]));
        write(1, ":\n", 2);
        option_ls_rr(ls->folder[ls->cpt], ls);
    }
}

void option_ls(struct my_ls_t *ls, DIR *directory)
{
    if (ls->lr == 1 && ls->rr == 0 && ls->ld == 0 && ls->l_r == 0 &&
    ls->lt == 0)
        option_ls_l(ls->folder[ls->cpt], directory);
    if (ls->lt == 1 && ls->rr == 0 && ls->ld == 0 && ls->l_r == 0 &&
    ls->lr == 0)
        option_ls_t(ls->folder[ls->cpt], directory);
    if (ls->rr == 1 && ls->l_r == 0 && ls->lt == 0 && ls->ld == 0 &&
    ls->lr == 0)
        option_ls_rmin(ls->folder[ls->cpt]);
    if (ls->l_r == 1 && ls->rr == 0 && ls->lt == 0 && ls->ld == 0 &&
    ls->lr == 0) {
        write(1, ls->folder[ls->cpt], my_strlen(ls->folder[ls->cpt]));
        write(1, ":\n", 2);
        option_ls_rcaps(ls->folder[ls->cpt], ls);
    }
    else
        other_options(ls);
}