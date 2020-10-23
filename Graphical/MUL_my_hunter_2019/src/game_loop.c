/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** game_loop.c
*/

#include "hunter.h"

static void init(t_game_fox *main_game)
{
    sfVector2f off = {4, 0};

    main_game->copy = 0;
    main_game->offset = off;
    main_game->my_game = my_games();
    main_game->clock_died = clock_died();
    main_game->sprites = my_fox(main_game->sprites);
    main_game->dead = my_dead_fox(main_game->dead);
    main_game->pause = pause_menu("sprites/pause.png");
    main_game->end_game = end_game("sprites/finish.png");
    main_game->my_cursor = cursor("sprites/target.png");
    main_game->background = my_background("sprites/background.png");
    main_game->gun_sound = play_gun("sprites/gun.ogg");
    main_game->score = 0;
    main_game->health = 4;
    score_print(main_game);
    health_print(main_game);
    random_pos(main_game);
}

void game_loop(sfRenderWindow *window, t_game_fox *main_game)
{
    sfEvent event;
    int temp = 0;
    sfMusic *music = main_music("sprites/main_music.ogg");

    init(main_game);
    sfMusic_play(music);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_setMouseCursorVisible(window, sfFalse);
        while (sfRenderWindow_pollEvent(window, &event))
            analyze_event(window, event, main_game, music);
        draw(window, main_game);
        pos_cursor(window, main_game);
        temp = game_event(main_game);
        if (temp == 2) {
            sfMusic_stop(music);
            end_menu(event, window, main_game);
            sfMusic_play(music);
        }
    }
    sfMusic_destroy(music);
}