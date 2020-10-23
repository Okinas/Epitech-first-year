/*
** EPITECH PROJECT, 2019
** my_compute_square_root
** File description:
** Function returns square root.
*/

int my_compute_square_root(int nb)
{
    int nbr = 1;

    if (nb <= 0)
        return (0);
    else if (nb == 1)
        return (1);
    while (nbr != nb/2) {
        nbr = nbr + 1;
        if (nbr * nbr == nb)
            return (nbr);
    }
    return (0);
}
