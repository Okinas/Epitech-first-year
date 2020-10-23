/*
** EPITECH PROJECT, 2019
** my_is_prime
** File description:
** Function returns 1 if number is prime and 0 if not.
*/

int my_is_prime(int nb)
{
    int index = nb - 1;

    if (nb <= 1)
        return (0);
    while (index > 1) {
        if (nb % index == 0)
            return (0);
        else
            index -= 1;
    }
    return (1);
}
