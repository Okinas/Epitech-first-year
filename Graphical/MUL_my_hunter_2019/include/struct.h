/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** struct.h
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct my_sprite
{
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
} t_my_sprite;

typedef struct my_game
{
    float seconds;
    sfClock *clock;
    sfTime time;
} t_my_game;

typedef struct my_sound
{
    sfSoundBuffer *buffer;
    sfSound *sound;
} t_my_sound;

typedef struct game_fox
{
    t_my_game *my_game;
    t_my_game *clock_died;
    t_my_sprite *sprites;
    t_my_sprite *dead;
    t_my_sprite *background;
    t_my_sprite *my_cursor;
    t_my_sprite *menu;
    t_my_sprite *pause;
    t_my_sprite *end_game;
    t_my_sound *gun_sound;
    sfVector2f offset;
    sfText *health_text;
    sfText *score_text;
    sfText *high_score_text;
    int high_score;
    int score;
    int copy;
    int health;
} t_game_fox;

#endif /*STRUCT_H_*/