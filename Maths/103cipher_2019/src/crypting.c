/*
** EPITECH PROJECT, 2019
** tmp
** File description:
** tmp.c
*/

#include "103cipher.h"

void crypting(char *str, char *key)
{
    cipher_t *m = malloc(sizeof(cipher_t));
    int size = sqrt(my_strlen(key) - 1) + 1;
    int length = (my_strlen(str) / size) + 1;
    int key_matrix[size][size];
    int str_matrix[length][size];
    int result_matrix[length][size];

    m->size = size;
    m->len = length;
    key_matrix_fct(size, key_matrix, key);
    str_matrix_fct(m, str_matrix, str);
    matrix_mul(m, str_matrix, key_matrix, result_matrix);
    printf("Key matrix:\n");
    print_key(size, key_matrix);
    printf("\nEncrypted message:\n");
    print_matrix(m, result_matrix);
    free(m);
}

void uncrypting(char *str, char *key)
{
    cipher_t *m = malloc(sizeof(cipher_t));
    int size = sqrt(my_strlen(key) - 1) + 1;
    int length = (my_strlen(str) / size) + 1;
    int key_matrix[size][size];
    int str_matrix[length][size];
    int result_matrix[length][size];

    m->size = size;
    m->len = length;
    key_matrix_fct(size, key_matrix, key);
    str_matrix_fct(m, str_matrix, str);
    matrix_mul(m, str_matrix, key_matrix, result_matrix);
    printf("Key matrix:\n");
    print_key(size, key_matrix);
    printf("\nDecrypted message:\n");
    print_matrix(m, result_matrix);
    free(m);
}