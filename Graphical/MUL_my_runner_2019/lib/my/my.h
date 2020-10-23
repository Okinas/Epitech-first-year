/*
** EPITECH PROJECT, 2019
** Lib H
** File description:
** hunter.h
*/

#ifndef READ_SIZE
#define READ_SIZE (10)
#include <stddef.h>

#endif /* READ_SIZE */

#ifndef MY_H_
#define MY_H_

void my_putchar(char);
int my_isneg(int);
void my_putnbr(int, char *);
void my_swap(int *, int *);
int my_putstr(char const *);
int my_strlen(char const *);
int my_getnbr(char const *str);
void my_sort_int_array(int *, int);
int my_compute_power_rec(int, int);
int my_compute_square_root(int);
int my_is_prime(int);
int my_find_prime_sup(int);
char *my_strcpy(char *, char const *);
char *my_strncpy(char *, char const *, int);
char *my_revstr(char *);
char *my_strstr(char *, char const *);
int my_strcmp(char const *, char const *);
int my_strncmp(char const *, char const *, int);
char *my_strupcase(char *);
char *my_strlowcase(char *);
char *my_strcapitalize(char *);
int my_str_isalpha(char const *);
int my_str_isnum(char const *);
int my_str_islower(char const *);
int my_str_isupper(char const *);
int my_str_isprintable(char const *);
int my_showstr(char const *);
int my_showmem(char const *, int);
int my_putnbr_base(int, char const *);
char *my_strcat(char *, char const *);
char *my_strncat(char *, char const *, int);
char **my_str_to_word_array(char const *);
char *my_strdup(char const *);
int alphanum(char);
int alloc(char const *);
int alloc_index(char const *, char **);
int array(char const *str, char **);
int lgth(char const *);
int length(char *);
int strleng(char *);
int leng(char const *);
int check_env(char **);
char *change_int_str(int);
int my_nblen(int);
char *get_next_line(int fd);

#endif /* MY_H_ */
