/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** credits.c
*/

#include "defense.h"

static void credits_free(credits_t *credits)
{
    sfText_destroy(credits->design);
    sfText_destroy(credits->dev);
    sfText_destroy(credits->tek);
    sfTexture_destroy(credits->background->texture);
    sfSprite_destroy(credits->background->sprite);
    free(credits->background);
    free(credits);
}

static void credits_draw(sfRenderWindow *win, credits_t *credits,
main_menu_t *menu)
{
    sfRenderWindow_clear(win, sfBlack);
    sfRenderWindow_drawSprite(win, credits->background->sprite, NULL);
    sfRenderWindow_drawText(win, credits->design, NULL);
    sfRenderWindow_drawText(win, credits->dev, NULL);
    sfRenderWindow_drawText(win, credits->tek, NULL);
    if (get_position((sfVector2f){108, 85}, 83, 83, win))
        sfRenderWindow_drawSprite(win, menu->quit_button_over->sprite,
        NULL);
    else
        sfRenderWindow_drawSprite(win, menu->quit_button->sprite,
        NULL);
    sfRenderWindow_display(win);
}

static void credits_events(sfRenderWindow *win, game_t *game, int *loop)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(win, &event)) {
        if (event.type == sfEvtMouseButtonPressed &&
        get_position((sfVector2f){108, 85}, 83, 83, win) == true) {
            sfSound_play(game->click->sound);
            *loop = 1;
        }
        if (event.type == sfEvtClosed) {
            *loop = -1;
            sfRenderWindow_close(win);
        }
    }
}

static void credits_init(credits_t *credits)
{
    credits->design = gen_txt((sfVector2f){400, 200},
    "Designed by Hiruko_Senpai", "sprites/scd.ttf", 60);
    credits->dev = gen_txt((sfVector2f){400, 400},
    "Developped by Okinas and SniiperRL", "sprites/scd.ttf", 60);
    credits->tek = gen_txt((sfVector2f){400, 600},
    "For Epitech Bordeaux", "sprites/scd.ttf", 60);
    credits->background = malloc(sizeof(sprite_t));
    credits->background->sprite = sfSprite_create();
    credits->background->texture = sfTexture_createFromFile(
    "sprites/background.jpg", NULL);
    sfSprite_setTexture(credits->background->sprite,
    credits->background->texture, sfFalse);
}

void credits(sfRenderWindow *win, int *status, main_menu_t *menu, game_t *game)
{
    int loop = 0;
    credits_t *credits = malloc(sizeof(credits_t));

    credits_init(credits);
    sfSprite_setPosition(menu->quit_button->sprite, (sfVector2f){108, 85});
    sfSprite_setPosition(menu->quit_button_over->sprite,
    (sfVector2f){108, 85});
    while (loop == 0) {
        credits_events(win, game, &loop);
        if (loop == -1) {
            *status = -1;
            break;
        }
        credits_draw(win, credits, menu);
    }
    sfSprite_setPosition(menu->quit_button->sprite, menu->quit_button->pos);
    sfSprite_setPosition(menu->quit_button_over->sprite,
    menu->quit_button_over->pos);
    credits_free(credits);
}