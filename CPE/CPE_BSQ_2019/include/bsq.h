/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** bsq.h
*/

#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "my.h"

#ifndef BSQ_H_
#define BSQ_H_

int len_line(char *);
int get_min(int, int, int);
int bsq(char *);
char *skip_line(char *);
int my_errors(int, int, char *);
int check_nbrlines(char *, int);
int check_lenlines(char *);

#endif /* BSQ_H_ */