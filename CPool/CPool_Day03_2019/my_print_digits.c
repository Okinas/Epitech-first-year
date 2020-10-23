/*
** EPITECH PROJECT, 2019
** my_print_digits
** File description:
** Display digits from 0 to 9.
*/

void my_putchar(char c);

int my_print_digits(void)
{
    char number;

    number = 48;
    while (number < 58)
    {
        my_putchar(number);
        number = number + 1;
    }
    return (0);
}
