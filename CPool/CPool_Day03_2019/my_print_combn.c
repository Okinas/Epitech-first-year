/*
** EPITECH PROJECT, 2019
** emacs
** File description:
** Display all different digits composed by n digits
*/

void my_putchar(char c);

int convert_char(int n, int nb, int f)
{
    char temp;

    if (f != n) {
        temp = nb % 10 + '0';
        convert_char(n, nb / 10, f + 1);
        my_putchar(temp); }
    return (0);
}

int convert_check(int n, int nb)
{
    int not_check = nb % 10;
    int nb_new = nb / 10;
    int check_nb_new = nb_new % 10;

    while (n != 1) {
        if (not_check > check_nb_new) {
            n = n - 1;
            nb = nb_new;
            not_check = nb % 10;
            nb_new = nb / 10;
            check_nb_new = nb_new % 10; }
        else
            return (1);
    }
    return (0);
}

int last(int n)
{
    int temp2 = 0;
    int min_digits = 9;
    int max_digits = 1;
    int latest = 0;

    while (temp2 != n) {
        latest = latest + (min_digits * max_digits);
        min_digits = min_digits - 1;
        max_digits = max_digits * 10;
        temp2 = temp2 + 1;
    }
    return (latest);
}

int my_print_combn(int n)
{
    int nb = 0;
    int m = last(n);

    while (nb != m + 1) {
        if (convert_check(n, nb) == 0) {
            convert_char(n, nb, 0);
            if (nb == m) {
                return (0); }
            else {
                my_putchar(',');
                my_putchar(' '); }
        }
        nb = nb + 1;
    }
    return (0);
}
