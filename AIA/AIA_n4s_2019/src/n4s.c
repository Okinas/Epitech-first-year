/*
** EPITECH PROJECT, 2019
** AIA_n4s_2019
** File description:
** n4s.c
*/

#include "n4s.h"

const char *send_command(char *cmd, char *nb)
{
    static char buffer[512];
    char *str = my_strcat(cmd, nb);

    dprintf(1, str);
    read(0, buffer, 512);
    buffer[511] = '\0';
    free(str);
    return buffer;
}

void get_info(car_t *car)
{
    const char *answer = send_command("GET_INFO_", "LIDAR\n");
    char **tab = my_str_to_word_array(answer);

    car->front = atof(tab[18]);
    car->left = atof(tab[3]);
    car->right = atof(tab[33]);
    for (int i = 0; tab[i]; i++)
        free(tab[i]);
    free(tab);
}

void turn_car(car_t *car)
{
    float distance[6] = {2000, 1500, 1000, 600, 400, 0};
    float direction[6] = {0.001, 0.05, 0.1, 0.15, 0.3, 0.5};
    int diff = car->left - car->right;
    char buffer[5];
    int i = 0;
    
    if (car->front <= 220 || car->right <= 10 || car->left <= 10)
        car->stuck = true;
    else
        car->stuck = false;
    for (; car->front < distance[i]; i++);
    gcvt(direction[i], 4, buffer);
    if ((diff > 0 && car->stuck) || (diff < 0 && !car->stuck))
        send_command("WHEELS_DIR:-", my_strcat(buffer, "\n"));
    else
        send_command("WHEELS_DIR:", my_strcat(buffer, "\n"));
}

const char *move_forwards(int front)
{
    float dist[7] = {2000, 1500, 1000, 600, 400, 0};
    float speed[7] = {0.8, 0.6, 0.4, 0.2, 0.1, 0.05};
    char buffer[4];
    int i = 0;

    while (front < dist[i])
        i += 1;
    gcvt(speed[i], 3, buffer);
    return send_command("CAR_FORWARD:", my_strcat(buffer, "\n"));
}

int n4s(void)
{
    car_t car = {2000, 0, 0, 0, 0};
    const char *answer = NULL;

    send_command("START_", "SIMULATION\n");
    while (!car.finished) {
        get_info(&car);
        if (!car.stuck)
            answer = move_forwards(car.front);
        else
            send_command("CAR_BACKWARDS:", "0.25\n");
        if (strstr(answer, "Track Cleared")) {
            car.finished = 1;
            break;
        }
        turn_car(&car);
    }
    send_command("STOP_", "SIMULATION\n");
    return 0;
}