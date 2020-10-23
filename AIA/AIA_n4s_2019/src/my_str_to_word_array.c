/*
** EPITECH PROJECT, 2019
** my_str_to_word_array
** File description:
** Splits a string into words
*/

#include <stdlib.h>

int isnum(char c)
{
    if (c == ':' || c == '\0')
        return (0);
    return (1);
}

int alloc_array(char const *str)
{
    int i = 0;
    int n = 0;

    while (str[i] != '\0') {
        if (isnum(str[i]) == 0)
            n += 1;
        i += 1;
    }
    n += 1;
    return (n);
}

int alloc_i_array(char const *str, char **arr)
{
    int i = 0;
    int n = 0;
    int k = 0;

    while (str[i] != '\0') {
        if (isnum(str[i]) == 1) {
            k += 1; }
        else if (isnum(str[i + 1]) == 1) {
            arr[n] = malloc(sizeof(char) * (k + 1));
            n += 1;
            k = 0;
        }
        i += 1;
    }
    arr[n] = malloc(sizeof(char) * (k + 1));
    return (0);
}

int while_array(char const *str, char **arr)
{
    int i = 0;
    int n = 0;
    int k = 0;

    while (str[i] != '\0') {
        if (isnum(str[i]) == 1 && isnum(str[i + 1]) == 1) {
            arr[n][k] = str[i];
            k += 1; }
        if (isnum(str[i]) == 0 && isnum(str[i + 1]) == 1 && n > 0) {
            k = 0; }
        if (isnum(str[i]) == 1 && isnum(str[i + 1]) == 0)
        {
            arr[n][k] = str[i];
            arr[n][k + 1] = '\0';
            n += 1;
            k = 0; }
        i += 1; }
    arr[n] = 0;
    return (0);
}

char **my_str_to_word_array(char const *str)
{
    char **arr;

    arr = malloc(sizeof(char *) * (alloc_array(str) + 1));
    alloc_i_array(str, arr);
    while_array(str, arr);
    return (arr);
}
