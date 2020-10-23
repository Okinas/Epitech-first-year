/*
** EPITECH PROJECT, 2019
** AIA_n4s_2019
** File description:
** n4s.h
*/

#ifndef N4S_H_
#define N4S_H_

#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct car {
    float front;
    float right;
    float left;
    bool stuck;
    bool finished;
} car_t;

char **my_str_to_word_array(char const *str);
int n4s(void);
char *my_strcat(char *dest, char const *src);
int get_abs(int nb);

#endif /* N4S_H_ */