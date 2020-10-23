/*
** EPITECH PROJECT, 2019
** tmp
** File description:
** window.c
*/

#include "runner.h"

static void wido_suite3(win_map_t *win)
{
    win->fact.x = 0.75;
    win->fact.y = 0.75;
    win->cover = sfTexture_createFromFile("sprites/cover.png", NULL);
    win->scover = sfSprite_create();
    sfSprite_setTexture(win->scover, win->cover, sfTrue);
    win->c_pos.x = 0;
    win->c_pos.y = 620;
    sfTexture_setRepeated(win->cover, sfTrue);
    sfSprite_setPosition(win->scover, win->c_pos);
    sfSprite_scale(win->sback1, win->fact);
    win->mode.width = 1280;
    win->mode.height = 720;
    win->mode.bitsPerPixel = 32;
    win->window = sfRenderWindow_create(win->mode, "A random runner",
    sfResize | sfClose, NULL);
    sfRenderWindow_setMouseCursorVisible(win->window, sfFalse);
    sfRenderWindow_setFramerateLimit(win->window, 60);
}

static void wido_suite2(win_map_t *win)
{
    win->back1 = sfTexture_createFromFile("sprites/tartarus.png", NULL);
    win->sback1 = sfSprite_create();
    win->back2 = sfTexture_createFromFile("sprites/cross.png", NULL);
    win->sback2 = sfSprite_create();
    sfSprite_setTexture(win->sback1, win->back1, sfTrue);
    sfSprite_setTexture(win->sback2, win->back2, sfTrue);
    win->pos.x = 0;
    win->pos.y = 20;
    win->offsetb2.top = 0;
    win->offsetb2.left = 0;
    win->offsetb2.width = 1280;
    win->offsetb2.height = 720;
    sfTexture_setRepeated(win->back2, sfTrue);
    sfSprite_setTextureRect(win->sback2, win->offsetb2);
    sfSprite_setPosition(win->sback2, win->pos);
    wido_suite3(win);
}

static void wido_suite(win_map_t *win)
{
    win->acc = 0;
    win->score->p_score.x = 0;
    win->score->p_score.y = 0;
    win->score->p_val.x = 240;
    win->score->p_val.y = 0;
    win->score->val = 0;
    win->score->score = "Score :";
    win->score->f_score = sfFont_createFromFile("sprites/font.ttf");
    win->score->f_val = sfFont_createFromFile("sprites/font.ttf");
    win->score->t_score = sfText_create();
    win->score->t_val = sfText_create();
    sfText_setString(win->score->t_score, win->score->score);
    sfText_setString(win->score->t_val, win->score->s_val);
    sfText_setFont(win->score->t_score, win->score->f_score);
    sfText_setFont(win->score->t_val, win->score->f_val);
    sfText_setCharacterSize(win->score->t_score, 35);
    sfText_setCharacterSize(win->score->t_val, 35);
    sfText_setPosition(win->score->t_val, win->score->p_val);
    wido_suite2(win);
}

void setup_wido(win_map_t *win)
{
    win->life = malloc(sizeof(life_t));
    win->score = malloc(sizeof(score_t));
    win->life->lose = 0;
    win->life->hit = 0;
    win->life->state.top = 0;
    win->life->state.left = 0;
    win->life->state.height = 170;
    win->life->state.width = 600;
    win->life->pos.x = 720;
    win->life->pos.y = 0;
    win->life->life = sfTexture_createFromFile("sprites/life.png", NULL);
    win->life->slife = sfSprite_create();
    sfSprite_setTexture(win->life->slife, win->life->life, sfTrue);
    sfSprite_setTextureRect(win->life->slife, win->life->state);
    sfSprite_setPosition(win->life->slife, win->life->pos);
    wido_suite(win);
}