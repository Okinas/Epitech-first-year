/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** sound.c
*/

#include "defense.h"

sound_t *gen_sound(char *filepath)
{
    sound_t *sound = malloc(sizeof(sound_t));

    sound->buffer = sfSoundBuffer_createFromFile(filepath);
    sound->sound = sfSound_create();
    sfSound_setBuffer(sound->sound, sound->buffer);
    return (sound);
}

sfMusic *gen_music(char *filepath)
{
    sfMusic *music = sfMusic_createFromFile(filepath);

    sfMusic_setLoop(music, sfTrue);
    sfMusic_setVolume(music, 10);
    return (music);
}