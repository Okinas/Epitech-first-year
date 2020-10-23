/*
** EPITECH PROJECT, 2019
** Lib H
** File description:
** hunter.h
*/

#ifndef MY_H_
#define MY_H_

int my_nblen(int);
void my_isneg(int);
int my_is_prime(int);
void my_putchar(char);
int check_env(char **);
char *my_revstr(char *);
char *change_int_str(int);
void my_swap(int *, int *);
int my_find_prime_sup(int);
char *my_strupcase(char *);
void my_putnbr(int, char *);
int my_strlen(char const *);
char *my_strlowcase(char *);
void my_putstr(char const *);
int my_showstr(char const *);
char *my_strdup(char const *);
char *my_strcapitalize(char *);
int my_str_isnum(char const *);
int my_compute_square_root(int);
int my_str_isalpha(char const *);
int my_str_islower(char const *);
int my_str_isupper(char const *);
int my_showmem(char const *, int);
int my_getnbr(char const *, int *);
void my_sort_int_array(int *, int);
int my_compute_power_rec(int, int);
int my_str_isprintable(char const *);
int my_putnbr_base(int, char const *);
char *my_strcpy(char *, char const *);
char *my_strstr(char *, char const *);
char *my_strcat(char *, char const *);
char **my_str_to_word_array(char const *, char *);
int my_strcmp(char const *, char const *);
char *my_strncat(char *, char const *, int);
char *my_strncpy(char *, char const *, int);
int my_strncmp(char const *, char const *, int);

#endif /* MY_H_ */
