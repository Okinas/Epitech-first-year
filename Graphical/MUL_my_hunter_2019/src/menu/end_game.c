/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** pause.c
*/

#include "hunter.h"

static void reset(t_game_fox *main)
{
    sfVector2f speed = {4, 0};

    main->score = 0;
    main->health = 4;
    main->offset = speed;
    score_print(main);
}

static void prepare_menu(sfRenderWindow *window, t_game_fox *main)
{
    int fd = open("game/score", O_RDONLY);

    main->high_score = read_score(fd);
    sfRenderWindow_setMouseCursorVisible(window, sfTrue);
    sfText_setCharacterSize(main->score_text, 75);
    if (main->high_score < main->score) {
        write_score(main);
        main->high_score = main->score;
    }
    high_score_print(main);
    close(fd);
}

void end_menu(sfEvent event, sfRenderWindow *window, t_game_fox *main)
{
    sfVector2f pos = {728, 255};

    prepare_menu(window, main);
    while (1) {
        draw_end(window, main, pos);
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtKeyPressed &&
            sfKeyboard_isKeyPressed(sfKeyEnter)) {
                reset(main);
                return;
            } if (event.type == sfEvtClosed || (event.type == sfEvtKeyPressed
            && sfKeyboard_isKeyPressed(sfKeySpace))) {
                sfRenderWindow_close(window);
                return;
            }
        }
    }
}
