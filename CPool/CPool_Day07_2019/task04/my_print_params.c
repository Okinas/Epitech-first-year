/*
** EPITECH PROJECT, 2019
** my_print_params
** File description:
** Display arguments
*/

#include <unistd.h>

void my_putchar(char c);

int my_putstr(char const *str);

int main(int ac, char **av)
{
    int index = 0;

    while (index != ac)
    {
        my_putstr(av[index]);
        my_putchar('\n');
        index += 1;
    }
    return (0);
}
