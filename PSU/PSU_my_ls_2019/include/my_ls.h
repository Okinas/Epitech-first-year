/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** ls.h
*/


#ifndef MY_LS_H_
#define MY_LS_H_

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>

#include "stddef.h"
#include "my.h"

struct my_ls_t {
    char **folder;
    char *filepath;
    int option;
    int lr;
    int ld;
    int lt;
    int cpt;
    int rr;
    int l_r;
};

void my_ls(int ac, char **av);
void struct_fill(struct my_ls_t *ls, int ac, char **av);
void access_rights(struct stat stats);
char *inspect_file(char *file, char *list);
void free_array(char **tab);
void print_all(struct stat stats, struct passwd *password,
struct group *group);

//? Functions
void simple_ls(DIR *dir);
void option_ls(struct my_ls_t *ls, DIR *directory);
void option_ls_l(char *tmp, DIR *directory);
void option_ls_t(char *dir, DIR *directory);
void option_ls_rmin(char *dir);
void option_ls_d(char *dir);
void option_ls_rcaps(char *dir, struct my_ls_t *ls);
void option_ls_rr(char *dir, struct my_ls_t *ls);

#endif /* MY_LS_H_ */