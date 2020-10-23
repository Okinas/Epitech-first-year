/*
** EPITECH PROJECT, 2019
** my_putnbr_base.c
** File description:
** Function that converts and displays a decimal nummber.
*/

int my_strlen(char const *str);

int my_compute_power_rec(int nb, int p);

int my_getnbr(char const *str);

int rec_pow(int nbr, int base, int p)
{
    int right = nbr % 10;
    int left = nbr / 10;
    int pow = my_compute_power_rec(base, p);

    if (left > 0)
        return ((right * pow) + rec_pow(left, base, p + 1));
    else
        return (right * pow);
}

int my_getnbr_base(char const *str, char const *base)
{
    int length = my_strlen(base);
    int base10;
    int n = 0;
    int nbr;

    nbr = my_getnbr(str);
    if (nbr < 0) {
        n = 1; }
    base10 = rec_pow(nbr, length, 0);
    if (n == 1)
        return (-base10);
    else
        return (base10);
}

