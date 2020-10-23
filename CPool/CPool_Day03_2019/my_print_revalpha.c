/*
** EPITECH PROJECT, 2019
** my_print_revalpha
** File description:
** Display letter from z to a.
*/

void my_putchar(char c);

int my_print_revalpha(void)
{
    char letter;

    letter = 122;   
    while (letter > 96)
    {
        my_putchar(letter);
        letter = letter - 1;
    }
    return (0);
}
