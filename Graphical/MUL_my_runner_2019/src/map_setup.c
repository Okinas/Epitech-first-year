/*
** EPITECH PROJECT, 2019
** tmp
** File description:
** map_setup.c
*/

#include "runner.h"

static void elements_add(char *line, level_t **map, int x, int y)
{
    while (line[y] != '\0') {
        if (line[y] == '1')
            add_ground(map, x, y);
        else if (line[y] == '2')
            add_spike(map, y);
        if (line[y] == '3')
            add_void(map, x, y);
        y += 1;
    }
}

static void create_end(level_t **map, char *line)
{
    int length = my_strlen(line);
    level_t *temp = *map;

    while (temp->next != NULL)
        temp = temp->next;
    temp->pos.x = length * 400;
    sfSprite_setPosition(temp->slevel, temp->pos);
}

static void setup_list(level_t **map)
{
    (*map)->level = sfTexture_createFromFile("sprites/end.png", NULL);
    (*map)->slevel = sfSprite_create();
    sfSprite_setTexture((*map)->slevel, (*map)->level, sfTrue);
    (*map)->pos.x = 0;
    (*map)->pos.y = 605;
    sfSprite_setPosition((*map)->slevel, (*map)->pos);
    (*map)->offset.x = -15;
    (*map)->offset.y = 0;
    (*map)->next = NULL;
    (*map)->prev = NULL;
    (*map)->what = -1;
    (*map)->high = -1;
    (*map)->col = -1;
}

static int map_check(char *line)
{
    int tmp = 0;

    if (line == NULL)
        return (1);
    while (line[tmp] != '\0') {
        if (line[tmp] != '3' && line[tmp] != '1')
            return (0);
        tmp += 1;
    }
    return (1);
}

void map_setup(level_t **map, char **av)
{
    int fd = open(av[1], O_RDONLY);
    char *line = get_next_line(fd);
    int x = 0;
    int y = 0;

    setup_list(map);
    while (line != NULL && map_check(line) == 0) {
        y = 0;
        elements_add(line, map, x, y);
        line = get_next_line(fd);
        x += 1;
    }
    create_end(map, line);
    y = 0;
    elements_add(line, map, x, y);
    free(line);
    close(fd);
}