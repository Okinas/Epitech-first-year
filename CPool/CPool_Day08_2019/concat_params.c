/*
** EPITECH PROJECT, 2019
** concat_params
** File description:
** Function that turns the command-line into a single string.
*/

#include <stdlib.h>
#include <stddef.h>

char *swap(int argc, char **argv, int length)
{
    int index = 0;
    int temp = 0;
    int temp2 = 0;
    char *str = malloc(sizeof(char) * (length + argc + 1));

    while (index < argc) {
        while (argv[index][temp] != '\0') {
            str[temp2] = argv[index][temp];
            temp += 1;
            temp2 += 1; }
        str[temp2] = '\n';
        temp2 += 1;
        temp = 0;
        index += 1;
    }
    str[temp2] = '\0';
    return (str);
}

char *concat_params(int argc, char **argv)
{
    int length = 0;
    int index = 0;
    int temp = 0;

    while (index < argc) {
        while (argv[index][temp] != '\0')
        {
            length += 1;
            temp += 1; }
        temp = 0;
        index += 1; }
    return (swap(argc, argv, length));
}
