/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** game_loop.c
*/

#include "sokoban.h"

static int game_events(my_game_t *game, int key, int status)
{
    int y = game->y;
    int x = game->x;

    if (key == 27)
        return (1);
    if (key == ' ') {
        free_all(game);
        put_in_doubletab(game, game->buffer);
        get_p(game, game->buffer);
    }
    if (key == KEY_RIGHT && (game->map[y][x + 1] != '#'))
        right_move(game);
    if (key == KEY_LEFT && (game->map[y][x - 1] != '#'))
        left_move(game);
    if (key == KEY_UP && (game->map[y - 1][x] != '#'))
        up_move(game);
    if (key == KEY_DOWN && (game->map[y + 1][game->x] != '#'))
        down_move(game);
    return (status);
}

static int length_x(char **map)
{
    int i = 0;

    while (map[0][i] != '\0') {
        i += 1;
    }
    return (i + 1);
}

static void print_map(my_game_t *game)
{
    int i = 0;
    int length = length_x(game->map) / 2;

    while (i < game->row) {
        mvprintw(i + LINES / 2 - length / 2, COLS / 2 - length, game->map[i]);
        i += 1;
    }
}

int game_loop(my_game_t *game, char *buffer, int status)
{
    int key;
    int event = 0;

    initscr();
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    while (1) {
        clear();
        print_map(game);
        refresh();
        if (status != 0 || event == 1)
            break;
        key = getch();
        event = game_events(game, key, status);
        status = o_check(game, buffer, status);
    }
    endwin();
    if (status == -1)
        status = 0;
    return (status);
}