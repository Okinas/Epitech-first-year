/*
** EPITECH PROJECT, 2019
** Lib H
** File description:
** My.h
*/

#ifndef MY_H_
#define MY_H_

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
char **my_str_to_word_array(char const *str);
char *my_strdup(char const *str);
int alphanum(char c);
int alloc(char const *str);
int alloc_index(char const *str, char **arr);
int array(char const *str, char **arr);
int lgth(char const *to_find);
int length(char *dest);
int strleng(char *str);
int leng(char const *str);

#endif /* MY_H_ */
