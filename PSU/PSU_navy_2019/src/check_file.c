/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** check_file.c
*/

#include "navy.h"

static int check_boat_len(int i, char *content)
{
    int len = content[i] - 48;
    int f_number = content[i + 3] - 48;
    int e_number = content[i + 6] - 48;

    if (f_number == e_number) {
        if (content[i + 5] - content[i + 2] + 1 != len)
            return (1);
    }
    else {
        if (e_number - f_number + 1 != len)
            return (1);
    }
    return (0);
}

int valid_len(char *content)
{
    int len = 0;

    for (int i = 0; content[i]; i++) {
        if (content[i] == '\n' && len != 7)
            return (1);
        else if (content[i] == '\n' && content[i + 1] != '\0')
            len = 0;
        else
            len += 1;
    }
    if (len != 8)
        return (1);
    return (0);
}

int valid_syntax(char *content)
{
    for (int i = 0; content[i]; i += 8) {
        if (content[i + 1] != ':' || content[i + 4] != ':' ||
        content[i + 2] < 'A' || content[i + 2] > 'H' ||
        content[i + 5] < 'A' || content[i + 5] > 'H')
            return (1);
        if (check_boat_len(i, content))
            return (1);
        if (content[i + 7] == '\0')
            break;
    }
    return (0);
}

int check_content(char *content)
{
    int line = 2;

    if (my_getnblines(content, 0) != 4)
        return (1);
    for (int i = 0; content[i] != '\0'; i += 1) {
        while (i != 0 && content[i - 1] != '\n' && content[i] != '\0')
            i += 1;
        if (content[i] == '\0')
            break;
        if (content[i] - 48 != line && content[i] != '\0')
            return (1);
        if (content[i + 2] != content[i + 5] &&
        content[i + 3] != content[i + 6])
            return (1);
        line += 1;
    }
    if (valid_len(content) || valid_syntax(content))
        return (1);
    return (0);
}