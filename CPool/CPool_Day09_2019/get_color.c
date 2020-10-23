/*
** EPITECH PROJECT, 2019
** get_color
** File description:
** Return the color as an int
*/

int get_color(unsigned char red, unsigned char green, unsigned char blue)
{
    int color = 0;

    color = color | red;
    color = color << 8;
    color = color | green;
    color = color << 8;
    color = color | blue;
    return (color);
}
