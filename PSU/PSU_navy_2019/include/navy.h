/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** navy.h
*/

#ifndef NAVY_H_
#define NAVY_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <signal.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"

enum state {
    SERVER,
    CLIENT
};

typedef struct main {
    int number;
    bool turn;
    bool touched;
    char *file;
    int state;
    int my_pid;
    char **my_map;
    int ennemy_pid;
    char **ennemy_map;
} t_main;

t_main s_main;

//? MAIN
int check_error(int ac, char **av);
t_main setup(int ac, char **av);
void connection(void);

//? GAME
int navy(void);
int attack(void);
int get_attack(void);

//? MAP
int fill_map(void);
void print_map(char **map, char *positions);
void hit_map(int pos, char letter, char **map);

//? UTILS
char *read_file(char *file);
void sig_handler(int sig);
void did_it_touch(int sig);
void send_number(int number);
int check_content(char *content);
int check_hit(int pos);
int check_pos(char *pos);
void free_all(void);

#endif /* NAVY_H_ */