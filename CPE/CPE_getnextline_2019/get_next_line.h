/*
** EPITECH PROJECT, 2019
** CPE_getnextline_2019
** File description:
** get_next_line.h
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#ifndef READ_SIZE
#define READ_SIZE (1);

#endif /* READ_SIZE */

#ifndef GET_NEXT_LINE_H_
#define GET_NEXT_LINE_H_

char *get_next_line(int fd);

#endif /* GET_NEXT_LINE_H_ */
