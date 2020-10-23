/*
** EPITECH PROJECT, 2019
** my_print_comb
** File description:
** Display all numbers composed by 3 different digits.
*/

void my_putchar(char c);

int printchar(int first, int second, int third)
{
    my_putchar(first);
    my_putchar(second);
    my_putchar(third);
    my_putchar(44);
    my_putchar(32);
    return (0);
}

int printchar_final(int first, int second, int third)
{
    my_putchar(first);
    my_putchar(second);
    my_putchar(third);
    return (0);
}

int my_print_comb(void)
{
    int first = 48;
    int second = 49;
    int third = 50;

    while (first < 55)
    {
        printchar(first, second, third);
        third = third + 1;
        if (third == 57) {
            printchar(first, second, third);
            second = second + 1;
            third = second + 1; }
        if (second == 56) {
            printchar(first, second, third);
            first = first + 1;
            second = first + 1;
            third = second + 1; }
    }
    printchar_final(first, second, third);
    return (0);
}
