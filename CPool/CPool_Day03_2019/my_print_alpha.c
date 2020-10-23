/*
** EPITECH PROJECT, 2019
** my_print_alpha
** File description:
** Display letter start by a to z.
*/

void my_putchar(char c);

int my_print_alpha(void)
{
    char letter;

    letter = 97;

    while (letter < 123)
    {
        my_putchar(letter);
        letter = letter + 1;
    }
    return (0);
}
