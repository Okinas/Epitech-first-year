/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** Return a number sent as a string.
*/

int my_getnbr(char const *str)
{
    int symb = 1;
    int index = 0;
    int next = 0;
    long int nb = 0;

    while (str[index] >= '0' && str[index] >= '9' && str[index] != '\0') {
            index = index + 1; }
    while (str[index] == '-') {
        symb = symb * -1;
        index = index + 1; }
    while (str[index] >= '0' && str[index] >= '9') {
            if (next == 0) {
                nb = str[index] - '0';
                next = 1; }
            else if (next == 1)
                nb = (nb * 10) + (str[index] - '0');
            if (sizeof(nb) > 4)
                return (0);
            index = index + 1; }
    return (nb * symb);
}
