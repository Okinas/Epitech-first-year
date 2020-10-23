/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** main_load.c
*/

#include "defense.h"

void main_load_buttons(main_menu_t *menu)
{
    menu->settings_button = gen_sprite((sfVector2f){1655, 85},
    (sfIntRect){1733, 205, 83, 83}, "sprites/sheet.png", (sfVector2f){1, 1});
    menu->settings_button_over = gen_sprite((sfVector2f){1655, 85},
    (sfIntRect){1390, 205, 83, 83}, "sprites/sheet.png", (sfVector2f){1, 1});
    menu->quit_button = gen_sprite((sfVector2f){1740, 85},
    (sfIntRect){1820, 205, 83, 83}, "sprites/sheet.png", (sfVector2f){1, 1});
    menu->quit_button_over = gen_sprite((sfVector2f){1738, 85},
    (sfIntRect){1475, 205, 83, 83}, "sprites/sheet.png", (sfVector2f){1, 1});
    menu->help_button = gen_sprite((sfVector2f){1570, 85},
    (sfIntRect){1641, 205, 83, 83}, "sprites/sheet.png", (sfVector2f){1, 1});
    menu->help_button_over = gen_sprite((sfVector2f){1570, 85},
    (sfIntRect){1298, 205, 83, 83}, "sprites/sheet.png", (sfVector2f){1, 1});
    menu->play = gen_sprite((sfVector2f){800, 685},
    (sfIntRect){52, 37, 338, 89}, "sprites/sheet.png", (sfVector2f){1, 1});
    menu->play_over = gen_sprite((sfVector2f){800, 685},
    (sfIntRect){52, 167, 338, 89}, "sprites/sheet.png", (sfVector2f){1, 1});
    menu->play_click = gen_sprite((sfVector2f){800, 685},
    (sfIntRect){52, 293, 338, 89}, "sprites/sheet.png", (sfVector2f){1, 1});
}

void main_load_exp(main_menu_t *menu, game_t *game)
{
    int exp = game->exp % 100;

    game->lvl = game->exp / 100 + 1;
    init_text(game);
    menu->lvl_icon = gen_sprite_icon((sfVector2f){105, 105}, game->lvl);
    menu->exp_bar = gen_sprite((sfVector2f){102, 263},
    (sfIntRect){1006, 33, 150, 35}, "sprites/sheet.png", (sfVector2f){1, 1});
    menu->exp_progress = gen_sprite((sfVector2f){102, 263},
    (sfIntRect){1006, 70, 150, 35}, "sprites/sheet.png", (sfVector2f){1, 1});
    menu->exp_progress->rect = (sfIntRect){1006, 70, exp * 1.5, 35};
    sfSprite_setTextureRect(menu->exp_progress->sprite,
    menu->exp_progress->rect);
}

main_menu_t *main_load(game_t *game)
{
    main_menu_t *menu = malloc(sizeof(main_menu_t));

    menu->settings = settings_load();
    menu->start_sound = gen_sound("sprites/game_start.ogg");
    menu->overlay = gen_sprite((sfVector2f){0, 0},
    (sfIntRect){0, 0, 1920, 1080}, "sprites/overlay.png", (sfVector2f){1, 1});
    menu->logo = gen_sprite((sfVector2f){749, 132},
    (sfIntRect){1457, 581, 446, 476}, "sprites/sheet.png", (sfVector2f){1, 1});
    main_load_buttons(menu);
    main_load_exp(menu, game);
    return (menu);
}