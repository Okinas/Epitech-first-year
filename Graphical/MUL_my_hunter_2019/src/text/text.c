/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** text.c
*/

#include "hunter.h"

void high_score_print(t_game_fox *main_game)
{
    sfVector2f pos = {728, 150};
    sfText *high_score = sfText_create();
    sfFont *font = sfFont_createFromFile("sprites/font.ttf");
    char *printable = change_int_str(main_game->high_score);

    sfText_setFont(high_score, font);
    sfText_setPosition(high_score, pos);
    sfText_setCharacterSize(high_score, 70);
    sfText_setColor(high_score, sfWhite);
    sfText_setString(high_score, printable);
    main_game->high_score_text = high_score;
    free(printable);
}

void score_print(t_game_fox *main_game)
{
    sfVector2f pos = {1100, 250};
    sfText *score = sfText_create();
    sfFont *font = sfFont_createFromFile("sprites/font.ttf");
    char *printable = change_int_str(main_game->score);

    sfText_setFont(score, font);
    sfText_setPosition(score, pos);
    sfText_setCharacterSize(score, 45);
    sfText_setColor(score, sfWhite);
    sfText_setString(score, printable);
    main_game->score_text = score;
    free(printable);
}

void health_print(t_game_fox *main_game)
{
    sfVector2f pos = {1190, 200};
    sfText *health = sfText_create();
    sfFont *font = sfFont_createFromFile("sprites/font.ttf");
    char *printable = change_int_str(main_game->health);

    sfText_setFont(health, font);
    sfText_setPosition(health, pos);
    sfText_setCharacterSize(health, 45);
    sfText_setColor(health, sfWhite);
    sfText_setString(health, printable);
    main_game->health_text = health;
    free(printable);
}