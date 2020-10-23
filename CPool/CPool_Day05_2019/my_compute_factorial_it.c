/*
** EPITECH PROJECT, 2019
** my_compute_factoorial_it
** File description:
** Functuon returns the factorial of a number.
*/

int my_compute_factorial_it(int nb)
{
    int nbi = 1;
    int p = 0;

    if (nb < 0 || nb > 12)
        return (0);
    if (nb == 1)
        return (1);
    while (p != nb) {
        nbi = nbi * (p + 1);
        p = p + 1;
    }
    return (nbi);
}
