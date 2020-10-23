/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** cursor.c
*/

#include "hunter.h"

void pos_cursor(sfRenderWindow *window, t_game_fox *main_game)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfVector2f pos = {mouse_pos.x - 36, mouse_pos.y - 36};

    sfSprite_setPosition(main_game->my_cursor->sprite, pos);
}

t_my_sprite *cursor(char const *filepath)
{
    t_my_sprite *my_cursor = malloc(sizeof(t_my_sprite));
    sfVector2f scale = {0.25, 0.25};

    my_cursor->texture = sfTexture_createFromFile(filepath, NULL);
    my_cursor->sprite = sfSprite_create();
    sfSprite_setTexture(my_cursor->sprite, my_cursor->texture, sfFalse);
    sfSprite_setScale(my_cursor->sprite, scale);
    return (my_cursor);
}