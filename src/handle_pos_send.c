/*
** EPITECH PROJECT, 2020
** B-PSU-101-NAN-1-1-navy-enzo.bonato
** File description:
** convert_signals
*/

#include "my.h"
#include "navy.h"
#include <sys/types.h>
#include <sys/sysinfo.h>
#include <stdio.h>

int is_pos_legal(char *pos)
{
    if (my_strlen(pos) != 2)
        return (-1);
    if (pos[0] < 'A' || pos[0] > 'H')
        return (-1);
    if (pos[1] < '1' || pos[1] > '8')
        return (-1);
}

int send_pos(char **enemy_pos)
{
    char *pos;
    ssize_t characters;
    ssize_t buffsize = 3;

    pos = malloc(sizeof(char) * buffsize);
    characters = getline(&pos, &buffsize, stdin);
    my_printf("attack: %s\n", pos);
    if (is_pos_legal(pos) == -1) {
        my_putstr("wrong position\n");
        return (2);
    }
    if (does_pos_touch_something(pos) == 1) {
        update_tab(pos, enemy_pos, 1);
        my_printf("%s: missed\n", pos);
        return (1);
    }
    if (does_pos_touch_something(pos) == 0) {
        update_tab(pos, enemy_pos, 0);
        my_printf("%s: hit\n", pos);
        return (0);
    }
}

int get_pos(char **my_pos)
{
    char *pos = get_pos_from_enemy();

    if (does_pos_touch_something(pos) == 1) {
        update_tab(pos, my_pos, 1);
        my_printf("%s: missed\n", pos);
        return (1);
    }
    if (does_pos_touch_something(pos) == 0) {
        update_tab(pos, my_pos, 0);
        my_printf("%s: hit\n", pos);
        return (1);
    }
}
