/*
** EPITECH PROJECT, 2019
** my_rev_params
** File description:
** Display arguments
*/

#include <unistd.h>

void my_putchar(char c);

int my_putstr(char *str);

int main(int ac, char **av)
{
    int index = ac - 1;

    while (index != -1)
    {
        my_putstr(av[index]);
        my_putchar('\n');
        index -= 1;
    }
    return (0);
}
