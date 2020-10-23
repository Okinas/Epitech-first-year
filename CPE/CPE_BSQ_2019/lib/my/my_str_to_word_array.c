/*
** EPITECH PROJECT, 2019
** my_str_to_word_array
** File description:
** Splits a strings into words
*/

#include <unistd.h>
#include <stdlib.h>

int alpha(char c)
{
    if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') ||
    (c >= 'A' && c <= 'Z'))
        return (1);
    else
        return (0);
}

int array(char const *str, char **array)
{
    int index = 0;
    int temp = 0;
    int t2 = 0;

    while (str[index] != '\0') {
        if (alpha(str[index]) == 1 && alpha(str[index + 1]) == 1) {
            array[temp][t2] = str[index];
            t2 += 1; }
        if (alpha(str[index]) == 1 && alpha(str[index + 1]) == 0) {
            array[temp][t2] = str[index];
            array[temp][t2 + 1] = '\0';
            t2 = 0;
            temp += 1; }
        if (alpha(str[index]) == 0 && alpha(str[index + 1]) == 1 && temp > 0) {
            t2 = 0; }
        index += 1;
    } array[temp] = 0;
    return (0);
}

void malloc_sizeof_str(char const *str, char **array)
{
    int index = 0;
    int temp2 = 0;
    int temp = 0;

    while (str[index] != '\0') {
        if (alpha(str[index] == 1))
            temp += 1;
        if (alpha(str[index + 1]) == 1) {
            array[temp2] = malloc(sizeof(char) * (temp2 + 1));
            temp = 0;
            temp2 += 1;
        }
        index += 1;
    }
    array[temp] = malloc(sizeof(char) * (temp2 + 1));
}

char **my_str_to_word_array(char const *str)
{
    int index = 0;
    int temp_1 = 0;
    char **array_1;

    while (str[index] != '\0') {
        if (alpha(str[index]) == 0)
            temp_1 += 1;
        index += 1;
    }
    temp_1 += 1;
    array_1 = malloc(sizeof(char *) * (temp_1 + 1));
    malloc_sizeof_str(str, array_1);
    array(str, array_1);
    return (array_1);
}
