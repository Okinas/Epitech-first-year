/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** Display for n digits.
*/

void my_putchar(char c);

int my_put_nbr(int nb)
{
    long nb1 = nb;

    if (nb1 < 0) {
        my_putchar('-');
        nb1 = -nb1; }
    if (nb1 >= 10) {
        my_put_nbr(nb1 / 10);
        my_put_nbr(nb1 % 10); }
    else
        my_putchar(nb1 + 48);
    return (0);
}
