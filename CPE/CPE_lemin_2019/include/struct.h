/*
** EPITECH PROJECT, 2019
** CPE_lemin_2019
** File description:
** struct.h
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct list_t {
    char *str;
    struct list_t **next;
    struct list_t *prev;
} list_t;

typedef struct file_t {
    int length;
    struct list_t *start;
    struct list_t *finish;
} file_t;

typedef struct ant_t {
    char *str;
    int i;
    struct ant_t *next;
} ant_t;

typedef struct way_t {
    char *str;
    struct way_t *next;
} way_t;

typedef struct algo_t {
    struct list_t *next;
    struct algo_t *end;
} algo_t;

#endif /* STRUCT_H_ */