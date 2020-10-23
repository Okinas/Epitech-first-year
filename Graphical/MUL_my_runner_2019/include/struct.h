/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** struct.h
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct my_sprite
{
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
} t_my_sprite;

typedef struct level
{
    struct level *next;
    struct level *prev;
    sfVector2f offset;
    sfSprite *slevel;
    sfTexture *level;
    sfVector2f pos;
    int what;
    int col;
    int high;
} level_t;

typedef struct player
{
    sfTexture *player;
    sfSprite *splayer;
    sfIntRect state;
    sfVector2f pos;
    sfVector2f grav;
    int run;
    int limit;
    int over;
    int falling;
} player_t;

typedef struct mob
{
    sfClock *clock;
    sfTime time;
    float seconds;
    sfTexture *mob;
    sfSprite *smob;
    sfIntRect state;
    sfVector2f pos;
    sfVector2f speed;
    sfVector2f fact;
    int sum;
} mob_t;

typedef struct score
{
    long val;
    char *score;
    char *s_val;
    sfFont *f_score;
    sfText *t_score;
    sfVector2f p_score;
    sfFont *f_val;
    sfText *t_val;
    sfVector2f p_val;
} score_t;

typedef struct life
{
    sfTexture *life;
    sfSprite *slife;
    sfIntRect state;
    sfVector2f pos;
    int hit;
    int lose;
} life_t;

typedef struct win_map
{
    sfRenderWindow *window;
    sfEvent event;
    sfClock *clock;
    sfTime time;
    score_t *score;
    life_t *life;
    float seconds;
    float acc;
    sfVideoMode mode;
    sfTexture *back1;
    sfSprite *sback1;
    sfVector2f fact;
    sfTexture *back2;
    sfSprite *sback2;
    sfVector2f pos;
    sfIntRect offsetb2;
    sfTexture *cover;
    sfSprite *scover;
    sfVector2f c_pos;
} win_map_t;

typedef struct my_runner
{
    t_my_sprite *main_menu;
    level_t *map;
    mob_t *mob;
    player_t *player;
    win_map_t *win;
} t_my_runner;

#endif /* STRUCT_H_ */