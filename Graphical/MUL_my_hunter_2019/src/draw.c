/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** draw.c
*/

#include "hunter.h"

void draw(sfRenderWindow *window, t_game_fox *main_game)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, main_game->background->sprite, NULL);
    fox_animation(main_game->sprites, main_game->my_game);
    sfRenderWindow_drawSprite(window, main_game->sprites->sprite, NULL);
    sfRenderWindow_drawText(window, main_game->score_text, NULL);
    sfRenderWindow_drawText(window, main_game->health_text, NULL);
    sfRenderWindow_drawSprite(window, main_game->my_cursor->sprite, NULL);
    sfRenderWindow_display(window);
}

void death_draw(sfEvent event, sfRenderWindow *window, t_game_fox *main,
sfMusic *music)
{
    sfVector2f pos = sfSprite_getPosition(main->sprites->sprite);
    int a = 0;

    pos.y -= 26;
    sfSprite_setPosition(main->dead->sprite, pos);
    while (a != 2) {
        while (sfRenderWindow_pollEvent(window, &event))
            analyze_event_death(window, event, main, music);
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, main->background->sprite, NULL);
        a = dead_fox_animation(main->dead, main->clock_died);
        sfRenderWindow_drawSprite(window, main->dead->sprite, NULL);
        sfRenderWindow_drawText(window, main->score_text, NULL);
        sfRenderWindow_drawText(window, main->health_text, NULL);
        sfRenderWindow_drawSprite(window, main->my_cursor->sprite, NULL);
        sfRenderWindow_display(window);
        pos_cursor(window, main);
    }
}

void draw_end(sfRenderWindow *window, t_game_fox *main_game, sfVector2f pos)
{
    sfRenderWindow_clear(window, sfBlack);
    sfText_setPosition(main_game->score_text, pos);
    sfRenderWindow_drawSprite(window, main_game->end_game->sprite, NULL);
    sfRenderWindow_drawText(window, main_game->score_text, NULL);
    sfRenderWindow_drawText(window, main_game->high_score_text, NULL);
    sfRenderWindow_display(window);
}

void draw_pause(sfRenderWindow *window, t_game_fox *main_game)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, main_game->pause->sprite, NULL);
    sfRenderWindow_display(window);
}