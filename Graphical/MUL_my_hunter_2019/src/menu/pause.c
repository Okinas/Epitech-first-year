/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** pause.c
*/

#include "hunter.h"

t_my_sprite *pause_menu(char const *filepath)
{
    t_my_sprite *pause = malloc(sizeof(t_my_sprite));

    pause->texture = sfTexture_createFromFile(filepath, NULL);
    pause->sprite = sfSprite_create();
    sfSprite_setTexture(pause->sprite, pause->texture, sfFalse);
    return (pause);
}

void my_pause(sfEvent event, sfRenderWindow *window, t_game_fox *main_game)
{
    sfMusic *music = pause_music("sprites/pause_music.ogg");

    sfRenderWindow_setMouseCursorVisible(window, sfTrue);
    sfMusic_play(music);
    while (1) {
        draw_pause(window, main_game);
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtKeyPressed &&
            sfKeyboard_isKeyPressed(sfKeyEscape)) {
                sfMusic_destroy(music);
                return;
            }
            if (event.type == sfEvtClosed || (event.type == sfEvtKeyPressed
            && sfKeyboard_isKeyPressed(sfKeySpace))) {
                sfRenderWindow_close(window);
                sfMusic_destroy(music);
                return;
            }
        }
    }
}
