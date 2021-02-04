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

int life_of_line(char **my_pos, int y, int x)
{
    int n = 0;

    while (x <= 16) {
        if (my_pos[y][x] == 'x')
            n++;
        x = x + 2;
    }
    return (n);
}

int is_game_finished(char **my_pos)
{
    int x = 2;
    int life = 14;
    int y = 2;

    while (y != 10) {
        life = life - life_of_line(my_pos, y, x);
        y++;
    }
    my_put_nbr(life);
    my_putchar('\n');
    return (life);
}

int does_pos_touch_something(char **array, char *pos)
{
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