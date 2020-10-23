/*
** EPITECH PROJECT, 2019
** my_compute_factorial_rec
** File description:
** Function returns facorial with a recursive.
*/

int factorial_rec(int nb)
{
    int factorial = nb;

    if (nb < 0 || nb > 12)
        return (0);
    else if (nb == 0)
        return (1);
    if (nb > 1) {
        factorial *= factorial_rec(nb - 1);
        nb = nb - 1;
    }
    return (factorial);
}

int my_compute_factorial_rec(int nb)
{
    int result = factorial_rec(nb);

    return (result);
}
