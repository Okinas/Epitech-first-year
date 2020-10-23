/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** menu_loop->c
*/

#include "defense.h"

static void main_free_struct(main_menu_t *menu)
{
    free(menu->overlay);
    free(menu->logo);
    free(menu->settings_button);
    free(menu->settings_button_over);
    free(menu->quit_button);
    free(menu->quit_button_over);
    free(menu->lvl_icon);
    free(menu->exp_bar);
    free(menu->exp_progress);
    free(menu->help_button);
    free(menu->help_button_over);
    free(menu);
}

static void main_free2(main_menu_t *menu)
{
    sfTexture_destroy(menu->help_button->texture);
    sfSprite_destroy(menu->help_button->sprite);
    sfTexture_destroy(menu->help_button_over->texture);
    sfSprite_destroy(menu->help_button_over->sprite);
    sfTexture_destroy(menu->play->texture);
    sfSprite_destroy(menu->play->sprite);
    sfTexture_destroy(menu->play_over->texture);
    sfSprite_destroy(menu->play_over->sprite);
    sfTexture_destroy(menu->play_click->texture);
    sfSprite_destroy(menu->play_click->sprite);
    main_free_struct(menu);
}

static void main_free(main_menu_t *menu, game_t *game)
{
    settings_free(menu);
    sfTexture_destroy(menu->overlay->texture);
    sfSprite_destroy(menu->overlay->sprite);
    sfTexture_destroy(menu->logo->texture);
    sfSprite_destroy(menu->logo->sprite);
    sfTexture_destroy(menu->settings_button->texture);
    sfSprite_destroy(menu->settings_button->sprite);
    sfTexture_destroy(menu->quit_button->texture);
    sfSprite_destroy(menu->quit_button->sprite);
    sfTexture_destroy(menu->settings_button_over->texture);
    sfSprite_destroy(menu->settings_button_over->sprite);
    sfTexture_destroy(menu->quit_button_over->texture);
    sfSprite_destroy(menu->quit_button_over->sprite);
    sfTexture_destroy(menu->lvl_icon->texture);
    sfSprite_destroy(menu->lvl_icon->sprite);
    sfTexture_destroy(menu->exp_bar->texture);
    sfSprite_destroy(menu->exp_bar->sprite);
    sfTexture_destroy(menu->exp_progress->texture);
    sfSprite_destroy(menu->exp_progress->sprite);
    sfText_destroy(game->text->level);
}

void main_menu(sfRenderWindow *win, game_t *game, int *status)
{
    main_menu_t *menu = main_load(game);
    sfMusic *music = gen_music("sprites/menu.ogg");

    if (game->loading == true)
        loading(win, status);
    if (game->music == true)
        sfMusic_play(music);
    while (*status == 0) {
        main_events(win, game, menu, status);
        main_draw(game, menu, win);
        if (game->music == false)
            sfMusic_pause(music);
    }
    if (game->music == true)
        sfMusic_pause(music);
    main_free(menu, game);
    main_free2(menu);
    sfMusic_destroy(music);
}