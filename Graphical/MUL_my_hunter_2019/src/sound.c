/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** sounds.c
*/

#include "hunter.h"

t_my_sound *play_gun(char const *filepath)
{
    t_my_sound *gun_sound = malloc(sizeof(t_my_sound));

    gun_sound->buffer = sfSoundBuffer_createFromFile(filepath);
    gun_sound->sound = sfSound_create();
    sfSound_setBuffer(gun_sound->sound, gun_sound->buffer);
    return (gun_sound);
}

sfMusic *main_music(char const *filepath)
{
    sfMusic *music = sfMusic_createFromFile(filepath);

    sfMusic_setLoop(music, sfTrue);
    sfMusic_setVolume(music, 10);
    return (music);
}

sfMusic *pause_music(char const *filepath)
{
    sfMusic *music = sfMusic_createFromFile(filepath);

    sfMusic_setLoop(music, sfTrue);
    sfMusic_setVolume(music, 20);
    return (music);
}