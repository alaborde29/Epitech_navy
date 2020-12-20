/*
** EPITECH PROJECT, 2020
** B-PSU-101-NAN-1-1-navy-enzo.bonato
** File description:
** game_rules
*/

#include "my.h"
#include "navy.h"
#include <sys/types.h>
#include <sys/sysinfo.h>
#include <stdio.h>

void life_of_line(char **my_pos, int y, int *x, int *life)
{
    while (x[0] <= 16) {
        if (my_pos[y][x[0]] >= '2' && my_pos[y][x[0]] <= '5')
            life[0]++;
        x[0] = x[0] + 2;
    }
}

int is_game_finished(char **my_pos)
{
    int x = 2;
    int life = 0;

    for (int y = 2; y != 10; y++)
        life_of_line(my_pos, y, &x, &life);
    return (life);
}

int does_pos_touch_something(char **array, char *pos)
{
    my_printf("position is %s\n", pos);
    if (array[pos[1] - '0' + 1][(pos[0] - 'A' + 2) * 2 - 2] != '.')
        return (0);
    return (1);
}

void update_tab(char **array, char *pos, int flag)
{
    if (flag == 0)
        array[pos[1] - '0' + 1][(pos[0] - 'A' + 2) * 2 - 2] = 'x';
    if (flag == 1)
        array[pos[1] - '0' + 1][(pos[0] - 'A' + 2) * 2 - 2] = 'o';
}