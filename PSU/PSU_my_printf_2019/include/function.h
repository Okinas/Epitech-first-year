/*
** EPITECH PROJECT, 2019
** Tap
** File description:
** function.h
*/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

#ifndef FUNCTION_H_
#define FUNCTION_H_

void (*dictionary[1])(char *flags, int index, char *over, va_list);

int flags_manager(char *f, va_list ap);
char *get_flags(int i, char *str);
void my_spaces(int precision, int length, int order);
int int_len(long int nb);
int int_len_u(unsigned long int nb);
long int spaces(long int nbr, int order, char *over);
unsigned long int spaces_u(unsigned long int nbr, int order, char *over);
long int signs(char *flags, long int nbr);
unsigned long int signs_u(char *flags, unsigned long int nbr);
long int length_modifier(char *flags, long int cast, va_list ap);
unsigned long int length_modifier_u(char *flags, unsigned long int cast,
va_list ap);

void int_function(char *flags, int index, char *over, va_list ap);
void char_function(char *flags, int index, char *over, va_list ap);
void string_function(char *flags, int index, char *over, va_list ap);
void binary_function(char *flags, int index, char *over, va_list ap);
void hexa_function(char *flags, int index, char *over, va_list ap);
void adress_function(char *flags, int index, char *over, va_list ap);
void unsigned_function(char *flags, int index, char *over, va_list ap);
void octal_function(char *flags, int index, char *over, va_list ap);
void showstr_function(char *flags, int index, char *over, va_list ap);
void percent_function(char *flags, int index, char *over, va_list ap);

#endif /* FUNCTION_H_*/