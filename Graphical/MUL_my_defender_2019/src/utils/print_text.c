/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** print_text.c
*/

#include "defense.h"

sfText *gen_txt(sfVector2f pos, char *txt, char *path, int size)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile(path);

    sfText_setFont(text, font);
    sfText_setPosition(text, pos);
    sfText_setCharacterSize(text, size);
    sfText_setColor(text, sfWhite);
    sfText_setString(text, txt);
    return (text);
}