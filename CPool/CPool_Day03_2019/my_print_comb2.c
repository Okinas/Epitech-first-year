/*
** EPITECH PROJECT, 2019
** my_print_comb2
** File description:
** Display in ascending order by two digits
*/

void my_putchar(char c);

int modulo(int first, int second)
{
    my_putchar(first/10 + 48);
    my_putchar(first%10 + 48);
    my_putchar(' ');
    my_putchar(second/10 + 48);
    my_putchar(second%10 + 48);

    if (first != 98 || second != 99) {
        my_putchar(',');
        my_putchar(' '); }
    return (0);
}


int my_print_comb2(void)
{
    int first = 00;
    int second = 01;

    while (first <= 98 && second <= 99)
    {
        if (first < second) {
            modulo(first, second); }
        if (second == 99) {
            first = first + 1;
            second = 0; }
        second = second + 1;
    }
    return (0);
}
