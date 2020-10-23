/*
** EPITECH PROJECT, 2019
** 103cipher_2019
** File description:
** 103cipher.h
*/

#include <unistd.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

#ifndef CIPHER_H_
#define CIPHER_H_

typedef struct cipher
{
    int len;
    int size;
} cipher_t;

void crypting(char *str, char *key);
void uncrypting(char *str, char *key);

//? Utils
void print_key(int size, int matrix[size][size]);
void print_matrix(cipher_t *m, int result_matrix[m->len][m->size]);
void key_matrix_fct(int size, int key_matrix[size][size], char *key);
void str_matrix_fct(cipher_t *m, int str_matrix[m->len][m->size], char *str);
void matrix_mul(cipher_t *m, int matrix1[m->size][m->size],
int matrix2[m->len][m->size], int result_matrix[m->len][m->size]);

#endif /* CIPHER_H_ */
