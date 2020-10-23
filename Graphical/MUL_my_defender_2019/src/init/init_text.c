/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** text.c
*/

#include "defense.h"

void init_text(game_t *game)
{
    sfVector2f pos_lvl = {155, 110};
    char *lvl = change_int_str(game->lvl);
    char *fps = change_int_str(game->fps);

    if (game->lvl >= 10)
        pos_lvl.x = 140;
    game->text = malloc(sizeof(struct text));
    if (game->text == NULL)
        return;
    game->text->level = gen_txt(pos_lvl, lvl, "sprites/font.otf", 95);
    free(lvl);
    game->text->fps = gen_txt((sfVector2f){1000, 548}, fps,
    "sprites/font.otf", 40);
    free(fps);
}