/*
** EPITECH PROJECT, 2019
** my_str_to_word_array
** File description:
** Splits a strings into words.
*/

#include <unistd.h>
#include <stdlib.h>

int alphanum(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return (1);
    else
        return (0);
}

int alloc(char const *str)
{
    int index = 0;
    int temp = 0;

    while (str[index] != '\0') {
        if (alphanum(str[index]) == 0)
            temp += 1;
        index += 1;
    }
    temp += 1;
    return (temp);
}

int alloc_index(char const *str, char **arr)
{
    int index = 0;
    int temp = 0;
    int temp2 = 0;

    while (str[index] != '\0') {
        if (alphanum(str[index]) == 1)
            temp2 += 1;
        else if (alphanum(str[index + 1]) == 1) {
            arr[temp] = malloc(sizeof(char) * (temp2 + 1));
            temp += 1;
            temp2 = 0;
        }
        index += 1;
    }
    arr[temp] = malloc(sizeof(char) * (temp2 + 1));
    return (0);
}

int array(char const *str, char **arr)
{
    int index = 0;
    int t = 0;
    int temp2 = 0;

    while (str[index] != '\0') {
        if (alphanum(str[index]) == 1 && alphanum(str[index + 1]) == 1) {
            arr[t][temp2] = str[index];
            temp2 += 1; }
        if (alphanum(str[index]) == 0 && alphanum(str[index + 1]) == 1 && t > 0)
            temp2 = 0;
        if (alphanum(str[index]) == 1 && alphanum(str[index + 1]) == 0) {
            arr[t][temp2] = str[index];
            arr[t][temp2 + 1] = '\0';
            t += 1;
            temp2 = 0; }
        index += 1; }
    arr[t] = 0;
    return (0);
}

char **my_str_to_word_array(char const *str)
{
    char **arr;

    arr = malloc(sizeof(char *) * (alloc(str) + 1));
    alloc_index(str, arr);
    array(str, arr);
    return (arr);
}
