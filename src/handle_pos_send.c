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

int is_pos_legal(char *pos, char **enemy_pos)
{
    if (my_strlen(pos) != 3)
        return (-1);
    if (pos[0] < 'A' || pos[0] > 'H')
        return (-1);
    if (pos[1] < '1' || pos[1] > '8')
        return (-1);
    if (enemy_pos[pos[1] - '0' + 1][(pos[0] - 'A' + 2) * 2 - 2] == 'x' \
    || enemy_pos[pos[1] - '0' + 1][(pos[0] - 'A' + 2) * 2 - 2] == 'o')
        return (-1);
}

int handle_reception(char **enemy_pos, char *pos)
{
    if (sig_reception == 1) {
        update_tab(enemy_pos, pos, 1);
        my_putchar(pos[0]);
        my_putchar(pos[1]);
        my_printf(": missed\n\n");
        return (1);
    }
    if (sig_reception == 2) {
        update_tab(enemy_pos, pos, 0);
        my_putchar(pos[0]);
        my_putchar(pos[1]);
        my_printf(": hit\n\n");
        return (0);
    }
}

int send_pos(char **enemy_pos, int pid)
{
    char *pos;
    ssize_t characters;
    ssize_t buffsize = 3;

    pos = malloc(sizeof(char) * buffsize);
    my_printf("attack: ");
    characters = getline(&pos, &buffsize, stdin);
    // pos[3] = '\0';
    if (is_pos_legal(pos, enemy_pos) == -1) {
        return (2);
    }
    send_pos_to_enemy(pos, pid);
    /*get_signal();
    pause();*/
    if (handle_reception(enemy_pos, pos) == 1)
        return (1);
    else
        return (0);
}

int get_pos(char **my_pos, int pid)
{
    char *pos;

    my_putstr("waiting for enemy's attack...\n");
    pos = get_pos_from_enemy();
    if (does_pos_touch_something(my_pos, pos) == 0) {
        my_printf("%s: hit\n", pos);
        update_tab(my_pos, pos, 0);
        kill(pid, SIGUSR2);
        usleep(15000);
        return (1);
    }
    if (does_pos_touch_something(my_pos, pos) == 1) {
        my_printf("%s: missed\n", pos);
        update_tab(my_pos, pos, 1);
        kill(pid, SIGUSR1);
        usleep(15000);
        return (1);
    }
}