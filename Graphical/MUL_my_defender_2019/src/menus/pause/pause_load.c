/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** pause_load.c
*/

#include "defense.h"

void pause_load_buttons(pause_menu_t *pause_m)
{
    pause_m->main_menu = gen_sprite((sfVector2f){878, 582},
    (sfIntRect){958, 322, 212, 61}, "sprites/sheet.png", (sfVector2f){1, 1});
    pause_m->main_menu_over = gen_sprite((sfVector2f){878, 582},
    (sfIntRect){958, 390, 212, 61}, "sprites/sheet.png", (sfVector2f){1, 1});
    pause_m->main_menu_click = gen_sprite((sfVector2f){878, 582},
    (sfIntRect){958, 462, 212, 61}, "sprites/sheet.png", (sfVector2f){1, 1});
    pause_m->resume = gen_sprite((sfVector2f){878, 506},
    (sfIntRect){457, 193, 212, 61}, "sprites/sheet.png", (sfVector2f){1, 1});
    pause_m->resume_over = gen_sprite((sfVector2f){878, 506},
    (sfIntRect){457, 263, 212, 61}, "sprites/sheet.png", (sfVector2f){1, 1});
    pause_m->resume_click = gen_sprite((sfVector2f){878, 506},
    (sfIntRect){457, 335, 212, 61}, "sprites/sheet.png", (sfVector2f){1, 1});
}

pause_menu_t *pause_load(void)
{
    pause_menu_t *pause_m = malloc(sizeof(pause_menu_t));

    pause_m->overlay = gen_sprite((sfVector2f){0, 0},
    (sfIntRect){0, 0, 1920, 1080}, "sprites/overlay.png", (sfVector2f){1, 1});
    pause_m->pause = gen_sprite((sfVector2f){772, 370},
    (sfIntRect){850, 665, 368, 297}, "sprites/sheet.png", (sfVector2f){1, 1});
    pause_m->quit_button = gen_sprite((sfVector2f){1740, 85},
    (sfIntRect){1820, 205, 83, 83}, "sprites/sheet.png", (sfVector2f){1, 1});
    pause_m->quit_button_over = gen_sprite((sfVector2f){1738, 85},
    (sfIntRect){1475, 205, 83, 83}, "sprites/sheet.png", (sfVector2f){1, 1});
    pause_load_buttons(pause_m);
    return (pause_m);
}