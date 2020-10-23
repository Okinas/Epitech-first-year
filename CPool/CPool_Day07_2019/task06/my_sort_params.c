/*
** EPITECH PROJECT, 2019
** my_sort_params
** File description:
** Display arguments on different lines.
*/

void my_putchar(char c);

int my_putstr(char const *str);

int my_strcmptwo(char const *s1, char const *s2)
{
    int index = 0;

    while (s1[index] && s2[index] && s1[index] == s2[index])
        index += 1;
    if (s1[index] > s2[index])
        return (1);
    if (s1[index] < s2[index])
        return (-1);
    if (s1[index] == s2[index])
        return (0);
    return (0);
}

int main(int argc, char **argv)
{
    int index = 0;
    int i = 1;
    void *swp;

    while (i < argc) {
        if (my_strcmptwo(argv[i - 1], argv[i]) == 1) {
            swp = argv[i];
            argv[i] = argv[i - 1];
            argv[i - 1] = swp;
            i = 0;
        }
        i += 1;
    }
    while (index < argc) {
        my_putstr(argv[index]);
        my_putchar('\n');
        index += 1;
    }
    return (0);
}
