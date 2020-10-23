/*
** EPITECH PROJECT, 2019
** MyHunter_bootstrap
** File description:
** hunter.h
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "struct.h"
#include "my.h"

#ifndef HUNTER_H_
#define HUNTER_H_

t_my_game *my_games(void);
t_my_game *clock_died(void);
void game_loop(sfRenderWindow *, t_game_fox *);
void free_ressources(sfRenderWindow *, t_game_fox *);
sfRenderWindow *create_window(unsigned int, unsigned int);

int game_event(t_game_fox *);
void analyze_event(sfRenderWindow *, sfEvent, t_game_fox *, sfMusic *);
void analyze_event_death(sfRenderWindow *, sfEvent, t_game_fox *, sfMusic *);

int begin_game(void);
int menu(sfRenderWindow *);
void draw_menu(sfRenderWindow *, t_game_fox *);
void my_pause(sfEvent, sfRenderWindow *, t_game_fox *);
t_my_sprite *my_background(char const *);
t_my_sprite *my_menu(char const *);
t_my_sprite *pause_menu(char const *);
t_my_sprite *end_game(char const *);

void end_menu(sfEvent, sfRenderWindow *, t_game_fox *);
void write_score(t_game_fox *);

void pos_cursor(sfRenderWindow *, t_game_fox *);
t_my_sprite *cursor(char const *);

int dead_fox_animation(t_my_sprite *, t_my_game *);
void fox_animation(t_my_sprite *, t_my_game *);
t_my_sprite *my_fox(t_my_sprite *);
t_my_sprite *my_dead_fox(t_my_sprite *);

void destroy_texture(t_game_fox *);
void destroy_sprite(sfRenderWindow *, t_game_fox *);

int read_score(int);
void random_pos(t_game_fox *);
void score_print(t_game_fox *);
void health_print(t_game_fox *);

void draw(sfRenderWindow *, t_game_fox *);
void death_draw(sfEvent, sfRenderWindow *, t_game_fox *, sfMusic *);
void draw_end(sfRenderWindow *, t_game_fox *, sfVector2f);
void draw_pause(sfRenderWindow *, t_game_fox *);
void high_score_print(t_game_fox *);

t_my_sound *play_gun(char const *);
sfMusic *main_music(char const *);
sfMusic *pause_music(char const *);

#endif /* HUNTER_H_ */