/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** begin.c
*/

#include "hunter.h"

void free_ressources(sfRenderWindow *window, t_game_fox *main_game)
{
    destroy_texture(main_game);
    destroy_sprite(window, main_game);
    free(main_game->background);
    free(main_game->my_game);
    free(main_game->sprites);
    free(main_game->my_cursor);
    free(main_game->pause);
    free(main_game->dead);
    free(main_game->end_game);
}

int begin_game(void)
{
    t_game_fox *main = malloc(sizeof(t_game_fox));
    sfRenderWindow *window;
    int temp = 0;

    if (main == NULL)
        return (84);
    window = create_window(1280, 720);
    main->menu = my_menu("sprites/menu.png");
    while (temp == 0) {
        temp = menu(window);
        draw_menu(window, main);
    }
    if (temp == 2)
        return (0);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    game_loop(window, main);
    free_ressources(window, main);
    free(main);
    return (0);
}