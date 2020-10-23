/*
** EPITECH PROJECT, 2019
** my_strstr
** File description:
** Reproduce the behavior of the str str function.
*/

static int lgth(char const *to_find)
{
    int loop = 0;

    while (to_find[loop])
        loop += 1;
    return (loop);
}

char *my_strstr(char *str, char const *to_find)
{
    int lo = 0;
    int loops = 0;
    int index = lgth(to_find);

    while (str[lo])
    {
        while (to_find[loops] && str[lo] && str[lo + loops] == to_find[loops])
            loops += 1;
        if (loops == index) {
            return (&(str[lo])); }
        lo += 1;
        loops = 0;
    }
    return (0);
}
