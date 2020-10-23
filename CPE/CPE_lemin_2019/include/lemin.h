/*
** EPITECH PROJECT, 2019
** CPE_lemin_2019
** File description:
** lemin.h
*/

#ifndef LEMIN_H_
#define LEMIN_H_

#include "struct.h"
#include <stdbool.h>

file_t *file_error(void);

way_t *follow_way(file_t *finish, char *str);

void end_program(way_t *way, int nbr);

file_t *graphic_create(void);
bool vertex(file_t *graphic, char *str, int nb);
int astar_algorithm(file_t *graphic, char *end);

//? Tools
bool form_check(char *str);
int count_arg(char *str, char c);
void print_msg(char *str, char c);
void display(int nbr);

//? Arguments check
int line_check(char *str, file_t *graphic);
bool check_corner(file_t *graphic, char *name, char *str);
char *first_arg(char *str, char c);
char *second_arg(char *str, char c);

#endif /* LEMIN_H_ */