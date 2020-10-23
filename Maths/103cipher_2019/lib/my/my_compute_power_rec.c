/*
** EPITECH PROJECT, 2019
** my_compute_power_rec
** File description:
** Functions return first argument raised to the power p.
*/

int power_rec(int nb, int p)
{
    int result = 0;

    if (nb == 2147483647 || nb == -2147483648)
        return (0);
    if (p < 0)
        return (0);
    else if (p == 0)
        return (1);
    result = nb * power_rec(nb, p - 1);
    return (result);
}

int my_compute_power_rec(int nb, int p)
{
    int final = 0;

    final = power_rec(nb, p);
    return (final);
}
