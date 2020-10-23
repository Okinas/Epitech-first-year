/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** defense.h
*/

#ifndef DEFENSE_H_
#define DEFENSE_H_

#include <stdbool.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <fcntl.h>
#include <time.h>
#include "struct.h"
#include "my.h"

//? Window, Sprites, Audio Init
int create_window(unsigned int width, unsigned int height);
sfMusic *gen_music(char *filepath);
sound_t *gen_sound(char *filepath);

//? Init
game_t *init_struct(void);
void init_map(game_t *game);
void init_text(game_t *game);

//? Main Loop
void save_data(game_t *game, int state);
int game_loop(sfRenderWindow *win, game_t *game);

//? Main menu
main_menu_t *main_load(game_t *game);
void main_load_exp(main_menu_t *menu, game_t *game);
void main_draw(game_t *game, main_menu_t *menu, sfRenderWindow *win);
void main_events(sfRenderWindow *win, game_t *game, main_menu_t *menu,
int *status);
void main_menu(sfRenderWindow *win, game_t *game, int *status);

void how_to_play(sfRenderWindow *win, game_t *game, main_menu_t *menu,
int *status);

//? Pause menu
void pause_menu(sfRenderWindow *win, game_t *game, int *status);
void pause_events(sfRenderWindow *win, game_t *game, pause_menu_t *pause,
int *loop);
void pause_draw(game_t *game, pause_menu_t *pause, sfRenderWindow *win,
int *loop);
pause_menu_t *pause_load(void);

//? Settings menu
void settings_draw(game_t *game, main_menu_t *menu, sfRenderWindow *win,
int *loop);
void settings_events(sfRenderWindow *win, game_t *game,
main_menu_t *menu, int *status);
void settings_menu(sfRenderWindow *win, game_t *game,
main_menu_t *menu, int *status);
settings_menu_t *settings_load(void);
void settings_free(main_menu_t *menu);
void credits(sfRenderWindow *win, int *status, main_menu_t *menu, game_t *game);

//? GAME
void game_menu(sfRenderWindow *win, game_t *game, int *status);
void game_draw(game_t *game, game_menu_t *gameplay, sfRenderWindow *win);
void game_events(sfRenderWindow *win, int *status,
game_menu_t *gameplay, game_t *game);
void game_free(game_menu_t *gameplay);
void create_new_sprite(sprite_t **list, char *filename, sfIntRect rect,
sfVector2f pos);
void create_sprite_list(sprite_t **list, char *filename, int nb,
sfIntRect rect);
void delete_sprite_list(sprite_t **list, int i);
game_menu_t *game_load(void);
int list_len(sprite_t *list);
void print_new_wave(sfRenderWindow *win, game_menu_t *gameplay, game_t *game);
void put_towers(sfVector2i mouse, game_menu_t *gameplay);
void check_around_towers(game_menu_t *gameplay);

//? End menu
void end_draw(game_t *game, end_menu_t *end, sfRenderWindow *win);
void end_events(sfRenderWindow *win, game_t *game, int *status);
void end_menu(sfRenderWindow *win, game_t *game, int *status);
end_menu_t *end_load(game_t *game);

//? Loading
void loading(sfRenderWindow *win, int *status);
loading_t *loading_load(void);
void loading_draw(sfRenderWindow *win, loading_t *load);

//? Utils general
sfText *gen_txt(sfVector2f pos, char *txt, char *path, int size);
sprite_t *gen_sprite(sfVector2f pos, sfIntRect rect, char *path,
sfVector2f size);
sprite_t *gen_sprite_icon(sfVector2f pos, int level);

float get_seconds(sfClock *clock);
bool get_position(sfVector2f pos, int width, int height, sfRenderWindow *win);

//? Utils struct
void free_struct(game_t *game);
void free_sprite_struct(sprite_t *sprite);

#endif /* DEFENSE_H_ */