/*
** EPITECH PROJECT, 2019
** my_is_prime
** File description:
** Task06
*/

int my_is_prime(int nb)
{
    int i = nb - 1;

    if (nb <= 0 || nb == 1)
        return (0);
    while (i > 1)
    {
        if (nb % i == 0)
            return (0);
        else
            i = i - 1;
    }
    return (1);
}
