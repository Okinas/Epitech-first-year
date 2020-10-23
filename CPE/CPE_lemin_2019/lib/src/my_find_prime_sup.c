/*
** EPITECH PROJECT, 2019
** my_find_prime_sup
** File description:
** Task07
*/

int my_find_prime_sup(int nb)
{
    int i = 2;
    int prime_nb = 0;

    while (nb <= 1)
        nb = nb + 1;
    while ((nb % i) != 0)
        i += 1;
    if (i != nb)
    {
        prime_nb = my_find_prime_sup(nb + 1);
        return (prime_nb);
    } else {
        return (nb);
    }
    return (0);
}
