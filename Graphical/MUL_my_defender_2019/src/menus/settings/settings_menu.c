/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** settings_menu->c
*/

#include "defense.h"

void settings_free_2(main_menu_t *menu)
{
    sfTexture_destroy(menu->settings->credits->texture);
    sfSprite_destroy(menu->settings->credits->sprite);
    sfTexture_destroy(menu->settings->credits_over->texture);
    sfSprite_destroy(menu->settings->credits_over->sprite);
    sfTexture_destroy(menu->settings->credits_click->texture);
    sfSprite_destroy(menu->settings->credits_click->sprite);
}

void settings_free(main_menu_t *menu)
{
    sfTexture_destroy(menu->settings->panel->texture);
    sfSprite_destroy(menu->settings->panel->sprite);
    sfTexture_destroy(menu->settings->panel_over->texture);
    sfSprite_destroy(menu->settings->panel_over->sprite);
    sfTexture_destroy(menu->settings->music_off->texture);
    sfSprite_destroy(menu->settings->music_off->sprite);
    sfTexture_destroy(menu->settings->music_on->texture);
    sfSprite_destroy(menu->settings->music_on->sprite);
    sfTexture_destroy(menu->settings->loading_off->texture);
    sfSprite_destroy(menu->settings->loading_off->sprite);
    sfTexture_destroy(menu->settings->loading_on->texture);
    sfSprite_destroy(menu->settings->loading_on->sprite);
    sfTexture_destroy(menu->settings->reset_data->texture);
    sfSprite_destroy(menu->settings->reset_data->sprite);
    sfTexture_destroy(menu->settings->reset_data_over->texture);
    sfSprite_destroy(menu->settings->reset_data_over->sprite);
    sfTexture_destroy(menu->settings->reset_data_click->texture);
    sfSprite_destroy(menu->settings->reset_data_click->sprite);
    settings_free_2(menu);
}

static void settings_setvalues(game_t *game, main_menu_t *menu)
{
    sfText_destroy(game->text->level);
    sfTexture_destroy(menu->lvl_icon->texture);
    sfSprite_destroy(menu->lvl_icon->sprite);
    sfTexture_destroy(menu->exp_bar->texture);
    sfSprite_destroy(menu->exp_bar->sprite);
    sfTexture_destroy(menu->exp_progress->texture);
    sfSprite_destroy(menu->exp_progress->sprite);
}

void settings_menu(sfRenderWindow *win, game_t *game, main_menu_t *menu,
int *status)
{
    int loop = 0;

    while (loop == 0) {
        settings_events(win, game, menu, &loop);
        if (loop == -1) {
            *status = -1;
            break;
        }
        settings_draw(game, menu, win, &loop);
    }
    settings_setvalues(game, menu);
    main_load_exp(menu, game);
    if (loop == 2)
        credits(win, status, menu, game);
}