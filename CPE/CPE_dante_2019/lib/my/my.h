/*
** EPITECH PROJECT, 2019
** Lib H
** File description:
** My.h
*/

#ifndef READ_SIZE
#define READ_SIZE (4096)
#endif

#ifndef __MY_H
#define __MY_H

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

typedef struct linked_list_t {
    char *value;
    int nb;
    int max;
    struct linked_list_t *next;
} list_t;

void my_putchar(char);
int my_isneg(int);
int my_put_nbr(int);
void my_swap(int *, int *);
int my_putstr(char const *);
int my_strlen(char const *);
int my_getnbr(char const *);
void my_sort_int_array(int *, int);
int my_compute_power_rec(int, int);
int my_compute_square_root(int);
int my_is_prime(int);
int my_find_prime_sup(int);
char *my_strcpy(char *, char const *);
char *my_strncpy(char *, char const *, int);
char *my_revstr(char *);
char *my_strstr(char *, char const *);
int my_nbcmp(char const *, char const *);
int my_strcmp(char const *, char const *);
int my_strncmp(char const *, char const *, int);
char *my_strupcase(char *);
char *my_strlowcase(char *);
char *my_strcapitalize(char *);
int my_str_isalpha(char const *);
int my_isalpha(char c);
int my_str_isnum(char const *);
int my_str_isalphanum(char const *str);
int my_str_islower(char const *);
int my_str_isupper(char const *);
int my_str_isprintable(char const *);
int my_showstr(char const *);
int my_showmem(char const *, int);
int my_putnbr_base(int, char const *);
char *my_strcat(char *, char const *);
char *my_strncat(char *, char const *, int);
char **my_str_to_word_array(char const *str);
char *my_strdup(char const *str);
int while_array(char const *str, char **arr);
int alloc_i_array(char const *str, char *arr);
int alloc_array(char const *str);
int lgth(char const *to_find);
int length(char *dest);
int strleng(char *str);
int leng(char const *str);
char *my_return_nbr_base(int nb, char *base);
void my_put_nbr_base(unsigned long int nb, char *base, char *cast);
int my_getnblines(char *str, int index);
void insert_in_list(list_t **list, char *value);
void append_in_list(list_t **list, char *value, int sticks);
void delete_list(list_t **list);
void delete_node(list_t **list, int i);
int get_list_nb(list_t *list, int node);
void print_list(list_t *list);
char *get_next_line(int fd);

#endif