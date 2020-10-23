/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** draw_menu->c
*/

#include "defense.h"

static void main_draw_play_button(main_menu_t *menu, sfRenderWindow *win)
{
    if (get_position(menu->play->pos, 338, 89, win) &&
    sfMouse_isButtonPressed(sfMouseLeft))
        sfRenderWindow_drawSprite(win, menu->play_click->sprite, NULL);
    else if (get_position(menu->play->pos, 338, 89, win))
        sfRenderWindow_drawSprite(win, menu->play_over->sprite,
        NULL);
    else
        sfRenderWindow_drawSprite(win, menu->play->sprite,
        NULL);
}

static void main_draw_buttons(main_menu_t *menu, sfRenderWindow *win)
{
    if (get_position(menu->settings_button->pos, 83, 83, win))
        sfRenderWindow_drawSprite(win, menu->settings_button_over->sprite,
        NULL);
    else
        sfRenderWindow_drawSprite(win, menu->settings_button->sprite,
        NULL);
    if (get_position(menu->quit_button->pos, 83, 83, win))
        sfRenderWindow_drawSprite(win, menu->quit_button_over->sprite,
        NULL);
    else
        sfRenderWindow_drawSprite(win, menu->quit_button->sprite,
        NULL);
    if (get_position(menu->help_button->pos, 83, 83, win))
        sfRenderWindow_drawSprite(win, menu->help_button_over->sprite,
        NULL);
    else
        sfRenderWindow_drawSprite(win, menu->help_button->sprite,
        NULL);
    main_draw_play_button(menu, win);
}

void main_draw(game_t *game, main_menu_t *menu, sfRenderWindow *win)
{
    sfRenderWindow_clear(win, sfBlack);
    sfRenderWindow_drawSprite(win, game->map->sprite, NULL);
    sfRenderWindow_drawSprite(win, menu->overlay->sprite, NULL);
    sfRenderWindow_drawSprite(win, menu->logo->sprite, NULL);
    main_draw_buttons(menu, win);
    sfRenderWindow_drawSprite(win, menu->lvl_icon->sprite, NULL);
    sfRenderWindow_drawText(win, game->text->level, NULL);
    sfRenderWindow_drawSprite(win, menu->exp_bar->sprite, NULL);
    sfRenderWindow_drawSprite(win, menu->exp_progress->sprite, NULL);
    sfRenderWindow_display(win);
}