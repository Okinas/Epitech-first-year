/*
** EPITECH PROJECT, 2019
** Tower_Defense
** File description:
** struct.h
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>

//  Saved in files
//  World, exp

typedef struct sprite {
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    sfVector2f pos;
    float speed;
    bool free;
    int type;
    int cost;
    int life;
    int range;
    int speed_shot;
    int damage;
    sfClock *timer_delay;
    struct sprite *next;
} sprite_t;

typedef struct sound_t {
    sfSoundBuffer *buffer;
    sfSound *sound;
} sound_t;

typedef struct text {
    sfText *exp;
    sfText *level;
    sfText *coins;
    sfText *kills;
    sfText *fps;
    int fps_state;
} text_t;

typedef struct credits_t {
    sprite_t *background;
    sfText *design;
    sfText *dev;
    sfText *tek;
} credits_t;

typedef struct loading_t {
    sfText *advice;
    sfClock *clock_round;
    sprite_t *round;
    sprite_t *player;
    sprite_t *player_back;
    sprite_t *background;
} loading_t;

typedef struct wave_t {
    sfText *wave_text;
    sfClock *wave_print;
} wave_t;

typedef struct game_menu_t {
    sprite_t tower_slots[6];
    sprite_t towers[4];
    sprite_t *mobs;
    sfClock *mobs_clock;
    sfClock *mobs_atk_clock;
    int wave;
    bool end_wave;
    int mob_nbr;
    bool boss;
    int coins;
    sfClock *coins_clock;
    int life;
    sprite_t *life_bar;
    wave_t *wave_start;
    bool click_tower;
    int click_tower_type;
} game_menu_t;

typedef struct end_menu_t {
    sfText *total_kill;
    sfText *total_coins;
} end_menu_t;

typedef struct pause_menu_t {
    sprite_t *overlay;
    sprite_t *pause;
    sprite_t *resume;
    sprite_t *resume_over;
    sprite_t *resume_click;
    sprite_t *main_menu;
    sprite_t *main_menu_over;
    sprite_t *main_menu_click;
    sprite_t *quit_button;
    sprite_t *quit_button_over;
} pause_menu_t;

typedef struct settings_menu_t {
    sprite_t *panel;
    sprite_t *panel_over;
    sprite_t *music_on;
    sprite_t *music_off;
    sprite_t *loading_on;
    sprite_t *loading_off;
    sprite_t *reset_data;
    sprite_t *reset_data_over;
    sprite_t *reset_data_click;
    sprite_t *credits;
    sprite_t *credits_over;
    sprite_t *credits_click;
    sprite_t *fps;
    sprite_t *fps_over;
    sprite_t *fps_click;
} settings_menu_t;

typedef struct main_menu_t {
    sound_t *start_sound;
    sprite_t *logo;
    sprite_t *overlay;
    sprite_t *lvl_icon;
    sprite_t *play_button;
    sprite_t *quit_button;
    sprite_t *quit_button_over;
    sprite_t *settings_button;
    sprite_t *settings_button_over;
    sprite_t *help_button;
    sprite_t *help_button_over;
    sprite_t *exp_bar;
    sprite_t *exp_progress;
    sprite_t *play;
    sprite_t *play_over;
    sprite_t *play_click;
    settings_menu_t *settings;
} main_menu_t;

typedef struct game {
    int total_mob;
    int total_coins;
    int world;
    int exp;
    int lvl;
    int fps;
    sprite_t *map;
    sprite_t *gui;
    sound_t *click;
    text_t *text;
    bool music;
    bool loading;
} game_t;