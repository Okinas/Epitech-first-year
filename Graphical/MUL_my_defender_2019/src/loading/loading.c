/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** loading.c
*/

#include "defense.h"

static int loading_event(sfRenderWindow *win, int *status)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(win, &event)) {
        if (event.type == sfEvtClosed) {
            *status = -1;
            sfRenderWindow_close(win);
            return (1);
        }
    }
    return (0);
}

static void loading_free(loading_t *load, sfClock *clock)
{
    sfText_destroy(load->advice);
    sfTexture_destroy(load->round->texture);
    sfSprite_destroy(load->round->sprite);
    sfTexture_destroy(load->background->texture);
    sfSprite_destroy(load->background->sprite);
    sfClock_destroy(load->clock_round);
    sfClock_destroy(clock);
    free(load->round);
    free(load->background);
    free(load);
}

void loading(sfRenderWindow *win, int *status)
{
    loading_t *load = loading_load();
    sfClock *clock = sfClock_create();
    float seconds = 0;

    while (seconds < 4) {
        seconds = get_seconds(clock);
        if (loading_event(win, status))
            break;
        loading_draw(win, load);
    }
    loading_free(load, clock);
}