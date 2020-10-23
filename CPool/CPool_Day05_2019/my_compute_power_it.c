/*
** EPITECH PROJECT, 2019
** my_compute_power_it
** File description:
** Return a function raised with the power argument.
*/

int my_compute_power_it(int nb, int p)
{
    int nbi = 1;

    if (p < 0)
        return (0);
    if (p == 0)
        return (1);
    while (p > 0)
    {
        nbi = nbi * nb;
        p = p - 1;
    }
    return (nbi);
}
