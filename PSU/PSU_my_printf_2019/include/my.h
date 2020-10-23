/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

void my_printf(char *str, ...);
void my_putchar(char);
void my_putstr(char const *);
int my_strlen(char const *);
void my_convertbase_octa(int);
char *my_revstr(char *);
int my_showstr_invalid(char *);
int my_getnbr(char const *);
void convert_base(long int nb, char *);
void convert_base_u(unsigned long int nb, char *);
int my_convertbase_octaspe(unsigned int nbr);
void my_putnbr_u(unsigned long int nb, char *base);

#endif /* MY_H_ */