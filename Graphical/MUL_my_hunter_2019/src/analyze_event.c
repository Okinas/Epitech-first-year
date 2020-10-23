/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** analyse_event.c
*/

#include "hunter.h"
#include <stdio.h>

void random_pos(t_game_fox *main_game)
{
    sfVector2f pos = sfSprite_getPosition(main_game->sprites->sprite);

    pos.x = -87;
    pos.y = rand() % 200 + 440;
    sfSprite_setPosition(main_game->sprites->sprite, pos);
}

static void mouse_compare(sfEvent all_event, t_game_fox *main_game,
sfRenderWindow *window, sfMusic *music)
{
    sfMouseButtonEvent event = all_event.mouseButton;
    sfVector2f pos = sfSprite_getPosition(main_game->sprites->sprite);
    int touched = 0;

    sfSound_play(main_game->gun_sound->sound);
    if ((event.x >= pos.x && event.x <= pos.x + 87) &&
    (event.y >= pos.y && event.y <= pos.y + 87)) {
        main_game->score += 1;
        main_game->copy += 1;
        score_print(main_game);
        touched = 1;
    }
    if (touched == 1) {
        death_draw(all_event, window, main_game, music);
        random_pos(main_game);
        main_game->dead->rect.left = 487;
    }
}

void analyze_event(sfRenderWindow *window, sfEvent event,
t_game_fox *main_game, sfMusic *music)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event.type == sfEvtMouseButtonPressed)
        mouse_compare(event, main_game, window, music);
    if (event.type == sfEvtKeyPressed &&
    sfKeyboard_isKeyPressed(sfKeyEscape)) {
        sfMusic_pause(music);
        my_pause(event, window, main_game);
        sfMusic_play(music);
    } if (event.type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyM))
        sfMusic_pause(music);
    if (event.type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyP))
        sfMusic_play(music);
}

void analyze_event_death(sfRenderWindow *window, sfEvent event,
t_game_fox *main, sfMusic *music)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event.type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyEscape)) {
        sfMusic_pause(music);
        my_pause(event, window, main);
        sfMusic_play(music);
    } if (event.type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyM))
        sfMusic_pause(music);
    if (event.type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyP))
        sfMusic_play(music);
    if (event.type == sfEvtMouseButtonPressed)
        sfSound_play(main->gun_sound->sound);
}