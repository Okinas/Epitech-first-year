/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** loading_load.c
*/

#include "defense.h"

static char *get_advice(void)
{
    int fd = open("game/advices.txt", O_RDONLY);
    int line = 0;
    char *advice = get_next_line(fd);

    line = rand() % 8;
    for (int i = 0; advice; i++) {
        if (line == i)
            break;
        free(advice);
        advice = get_next_line(fd);
    }
    close(fd);
    return (advice);
}

loading_t *loading_load(void)
{
    char *ad = get_advice();
    loading_t *load = malloc(sizeof(loading_t));

    load->clock_round = sfClock_create();
    load->advice = gen_txt((sfVector2f){250, 200}, ad, "sprites/scd.ttf", 50);
    load->round = gen_sprite((sfVector2f){1756, 850},
    (sfIntRect){0, 0, 197, 197}, "sprites/round.png", (sfVector2f){0.8, 0.8});
    load->background = malloc(sizeof(sprite_t));
    load->background->sprite = sfSprite_create();
    load->background->texture = sfTexture_createFromFile(
    "sprites/background.jpg", NULL);
    sfSprite_setTexture(load->background->sprite, load->background->texture,
    sfFalse);
    return (load);
}