/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** settings_load.c
*/

#include "defense.h"

static void settings_load_buttons(settings_menu_t *settings)
{
    settings->music_on = gen_sprite((sfVector2f){1040, 256},
    (sfIntRect){481, 21, 81, 45}, "sprites/sheet.png", (sfVector2f){1, 1});
    settings->music_off = gen_sprite((sfVector2f){1040, 256},
    (sfIntRect){481, 79, 81, 45}, "sprites/sheet.png", (sfVector2f){1, 1});
    settings->loading_on = gen_sprite((sfVector2f){1040, 346},
    (sfIntRect){481, 21, 81, 45}, "sprites/sheet.png", (sfVector2f){1, 1});
    settings->loading_off = gen_sprite((sfVector2f){1040, 346},
    (sfIntRect){481, 79, 81, 45}, "sprites/sheet.png", (sfVector2f){1, 1});
}

static void settings_load_reset(settings_menu_t *settings)
{
    settings->reset_data = gen_sprite((sfVector2f){855, 415},
    (sfIntRect){1687, 319, 212, 61}, "sprites/sheet.png", (sfVector2f){1, 1});
    settings->reset_data_over = gen_sprite((sfVector2f){855, 415},
    (sfIntRect){1687, 389, 212, 61}, "sprites/sheet.png", (sfVector2f){1, 1});
    settings->reset_data_click = gen_sprite((sfVector2f){855, 415},
    (sfIntRect){1687, 459, 212, 61}, "sprites/sheet.png", (sfVector2f){1, 1});
}

static void settings_load_credits(settings_menu_t *settings)
{
    settings->credits = gen_sprite((sfVector2f){855, 481},
    (sfIntRect){1443, 321, 212, 61}, "sprites/sheet.png", (sfVector2f){1, 1});
    settings->credits_over = gen_sprite((sfVector2f){855, 481},
    (sfIntRect){1443, 390, 212, 61}, "sprites/sheet.png", (sfVector2f){1, 1});
    settings->credits_click = gen_sprite((sfVector2f){855, 481},
    (sfIntRect){1443, 460, 212, 61}, "sprites/sheet.png", (sfVector2f){1, 1});
}

static void settings_load_fps(settings_menu_t *settings)
{
    settings->fps = gen_sprite((sfVector2f){855, 546},
    (sfIntRect){1204, 321, 212, 61}, "sprites/sheet.png", (sfVector2f){1, 1});
    settings->fps_over = gen_sprite((sfVector2f){855, 546},
    (sfIntRect){1204, 390, 212, 61}, "sprites/sheet.png", (sfVector2f){1, 1});
    settings->fps_click = gen_sprite((sfVector2f){855, 546},
    (sfIntRect){1204, 460, 212, 61}, "sprites/sheet.png", (sfVector2f){1, 1});
}

settings_menu_t *settings_load(void)
{
    settings_menu_t *settings = malloc(sizeof(settings_menu_t));

    settings->panel = gen_sprite((sfVector2f){749, 132},
    (sfIntRect){12, 466, 405, 561}, "sprites/sheet.png", (sfVector2f){1, 1});
    settings->panel_over = gen_sprite((sfVector2f){750, 132},
    (sfIntRect){430, 466, 405, 571}, "sprites/sheet.png", (sfVector2f){1, 1});
    settings_load_buttons(settings);
    settings_load_reset(settings);
    settings_load_credits(settings);
    settings_load_fps(settings);
    return (settings);
}