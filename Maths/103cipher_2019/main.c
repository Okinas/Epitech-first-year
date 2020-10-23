/*
** EPITECH PROJECT, 2019
** 103cipher_2019
** File description:
** main.c
*/

#include "103cipher.h"

static void help(void)
{
    write(1, "USAGE\n"
    "    ./103cipher message key flag\n\n"
    "DESCRIPTION\n"
    "    message    a message, made of ASCII characters\n"
    "    key        the encryption key, made of ASCII characters\n"
    "    flag       0 for the message to be encrypted, 1 to be decrypted\n"
    , 231);
}

int main(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        help();
        return (0);
    }
    if (ac == 4 && my_strcmp(av[3], "0") == 0)
        crypting(av[1], av[2]);
    else if (ac == 4 && my_strcmp(av[3], "1") == 0)
        uncrypting(av[1], av[2]);
    else {
        write(1, "BAD ARGUMENTS\n", 14);
        return (84);
    }
    return (0);
}