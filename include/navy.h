/*
** EPITECH PROJECT, 2020
** B-PSU-101-NAN-1-1-navy-enzo.bonato
** File description:
** navy
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef NAVY_H_
#define NAVY_H_

typedef struct vector2i_s
{
    int x;
    int y;
}vector2i_t;


int error(int ac, char **av);
char *read_file(char *path, char *buffer);
int is_size_normal(char *str);
void navy(char *pid, char *pos_path);
char **setup_blank_tab(void);
void put_boats_in_tab(char **array, char *pos_path);
char **split_lines(char *str, int tab_size);
int find_boat_orientation(char *str);
vector2i_t create_vetor2i(int x, int y);
void my_strdup(char *src, char *dest);
#endif /* !NAVY_H_ */
