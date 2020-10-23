/*
** EPITECH PROJECT, 2019
** my_putnbr_base.c
** File description:
** Function that converts and displays a decimal nummber.
*/

int my_strlen(char const *str);

int my_compute_power_rec(int nb, int p);

void my_putchar(char c);

int rec_power(int nbr, int base, int p)
{
    int right = nbr % 10;
    int left = nbr / 10;
    int pow = my_compute_power_rec(base, p);

    if (left > 0)
        return ((right * pow) + rec_power(left, base, p + 1));
    else
        return (right * pow);
}

int display(int nbr)
{
    if (nbr < 10)
        my_putchar(nbr + 48);
    else {
        display(nbr / 10);
        display(nbr % 10); }
    return (0);
}

int my_putnbr_base(int nbr, char const *base)
{
    int length = my_strlen(base);
    int base10;

    if (nbr < 0) {
        my_putchar('-');
        nbr = nbr * - 1; }
    base10 = rec_power(nbr, length, 0);
    display(base10);
    return (0);
}

