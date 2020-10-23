/*
** EPITECH PROJECT, 2019
** tmp
** File description:
** key_functions.c
*/

#include "103cipher.h"

void matrix_mul(cipher_t *m, int matrix1[m->size][m->size],
int matrix2[m->len][m->size], int result_matrix[m->len][m->size])
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (i != m->len) {
        j = 0;
        while (j != m->size) {
            result_matrix[i][j] = 0;
            k = 0;
            while (k != m->size) {
                result_matrix[i][j] += matrix1[i][k] * matrix2[k][j];
                k += 1;
            }
            j += 1;
        }
        i += 1;
    }
}

void key_matrix_fct(int size, int key_matrix[size][size], char *key)
{
    int a = 0;
    int i = 0;
    int j = 0;

    while (i < size) {
        j = 0;
        while (j < size) {
            if (key[a] != '\0') {
                key_matrix[i][j] = key[a];
                a += 1;
            }
            else
                key_matrix[i][j] = 0;
            j += 1;
        }
        i += 1;
    }
}

void str_matrix_fct(cipher_t *m, int str_matrix[m->len][m->size], char *str)
{
    int a = 0;
    int i = 0;
    int j = 0;

    while (i < m->len) {
        j = 0;
        while (j < m->size) {
            if (str[a]) {
                str_matrix[i][j] = str[a];
                a += 1;
            }
            else
                str_matrix[i][j] = 0;
            j += 1;
        }
        i += 1;
    }
}

void print_key(int size, int matrix[size][size])
{
    int i = 0;
    int j = 0;

    while (i < size) {
        j = 0;
        while (j < size - 1) {
            printf("%d\t", matrix[i][j]);
            j += 1;
        }
        printf("%d\n", matrix[i][size - 1]);
        i += 1;
    }
}

void print_matrix(cipher_t *m, int result_matrix[m->len][m->size])
{
    int i = 0;
    int j = 0;

    if (m->size == 1)
        m->len -= 1;
    while (i < m->len) {
        j = 0;
        while (j < m->size) {
            if (i == m->len -1 && j == m->size - 1)
                printf("%d\n", result_matrix[i][j]);
            else
                printf("%d ", result_matrix[i][j]);
            j += 1;
        }
        i += 1;
    }
}