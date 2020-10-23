/*
** EPITECH PROJECT, 2019
** my_find_prime_sup
** File description:
** Display
*/

int my_find_prime_sup(int nb)
{
    int temp = 2;
    int prime = 0;

    while (nb <= 1)
        nb += 1;
    while ((nb % temp) != 0)
        temp += 1;
    if (temp != nb)
        prime = my_find_prime_sup(nb + 1);
    return (nb);
}