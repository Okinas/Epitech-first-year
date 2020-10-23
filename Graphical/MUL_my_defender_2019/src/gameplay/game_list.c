/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** game_list.c
*/

#include "defense.h"

int list_len(sprite_t *list)
{
    int len = 0;

    if (list == NULL)
        return (0);
    for (; list; list = list->next)
        len += 1;
    return (len);
}

void delete_sprite_list(sprite_t **list, int i)
{
    sprite_t *tmp = *list;
    sprite_t *save = *list;

    if (*list == NULL)
        return;
    if ((*list)->next == NULL) {
        *list = NULL;
        return;
    }
    if (i == 0) {
        *list = (*list)->next;
        sfTexture_destroy(save->texture);
        sfSprite_destroy(save->sprite);
        return;
    }
    for (int j = 0; j < i - 1; j++)
        tmp = tmp->next;
    save = tmp->next;
    tmp = tmp->next->next;
}

void create_new_sprite(sprite_t **list, char *filename, sfIntRect rect,
sfVector2f pos)
{
    sprite_t *element;
    sprite_t *temp = *list;

    element = malloc(sizeof(sprite_t));
    element->sprite = sfSprite_create();
    element->texture = sfTexture_createFromFile(filename, NULL);
    element->rect = rect;
    element->pos = pos;
    element->life = 100;
    sfSprite_setTexture(element->sprite, element->texture, sfFalse);
    sfSprite_setTextureRect(element->sprite, element->rect);
    sfSprite_setPosition(element->sprite, element->pos);
    element->next = NULL;
    if (*list == NULL) {
        *list = element;
    } else {
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = element;
    }
}

void create_sprite_list(sprite_t **list, char *object, int nb, sfIntRect rect)
{
    int x_pos = 0;
    int y_pos = 0;

    if (my_strcmp(object, "mobs") == 0) {
        for (int i = 0; i < nb; i++) {
            srand(rand());
            x_pos = rand() % 400 - 500;
            y_pos = rand() % 200 + 491;
            create_new_sprite(list, "sprites/gamesheet.png", rect,
            (sfVector2f){x_pos, y_pos});
        }
    }
}