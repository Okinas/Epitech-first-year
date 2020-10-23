/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** init_struct.c
*/

#include "defense.h"

char *read_file(char *str)
{
    int fd = open("game/data.sav", O_RDONLY);
    char *data = get_next_line(fd);

    if (fd <= 0)
        return (NULL);
    while (data) {
        if (my_strncmp(data, str, my_strlen(str)) == 0)
            break;
        free(data);
        data = get_next_line(fd);
    }
    close (fd);
    return (data);
}

game_t *init_struct(void)
{
    game_t *game = malloc(sizeof(game_t));

    if (game == NULL)
        return (NULL);
    game->total_mob = 0;
    game->total_coins = 0;
    game->text = malloc(sizeof(text_t));
    game->world = my_getnbr(read_file("world"));
    game->exp = my_getnbr(read_file("exp"));
    game->music = true;
    game->click = gen_sound("sprites/click.ogg");
    game->loading = true;
    game->fps = 60;
    init_map(game);
    if (game->world == -1)
        return (NULL);
    return (game);
}