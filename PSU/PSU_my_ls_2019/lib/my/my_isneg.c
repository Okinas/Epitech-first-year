/*
** EPITECH PROJECT, 2019
** my_isneg
** File description:
** Say when number are negative or positive.
*/

#include <unistd.h>

void my_isneg(int n)
{
    if (n < 0)
        write(1, "N", 1);
    else
        write(1, "P", 1);
}
