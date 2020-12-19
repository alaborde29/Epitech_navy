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

int does_pos_touch_something(char **array, char *pos)
{
    send_pos_to_enemy(pos);
    if (array[(pos[0] - 'A') * 2 + 2][pos[1] - '0' + 2] != '.')
        return (0);
    return (1);
}

void update_tab(char **array, char *pos, int flag)
{
    if (flag == 0)
        array[(pos[0] - 'A') * 2 + 2][pos[1] - '0' + 2] = 'x';
    if (flag == 1)
        array[(pos[0] - 'A') * 2 + 2][pos[1] - '0' + 2] = 'o';
}