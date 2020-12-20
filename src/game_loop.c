/*
** EPITECH PROJECT, 2020
** B-PSU-101-NAN-1-1-navy-enzo.bonato
** File description:
** game_loop
*/

#include "my.h"
#include "navy.h"
#include <sys/types.h>
#include <sys/sysinfo.h>

int send_game_statut(char **my_pos, int pid)
{
    if (is_game_finished(my_pos) == 0) {
        kill(pid, SIGUSR2);
        usleep(15000);
        my_putstr("Enemy won\n");
        return (0);
    }
    else {
        kill(pid, SIGUSR1);
        usleep(15000);
        return (1);
    }
}

int did_i_won(void)
{
    get_signal();
    pause();
    if (sig_reception == 2) {
        my_putstr("I won\n");
        return (0);
    }
    return (1);
}

void show_game_tabs(char **my_pos, char **enemy_pos)
{
    my_putstr("my positions:\n");
    my_show_word_array(my_pos);
    my_putchar('\n');
    my_putstr("enemy's positions:\n");
    my_show_word_array(enemy_pos);
    my_putchar('\n');
}

void attack_turn(char **enemy_pos, int pid)
{
    int return_of_send_pos = 2;

    while (return_of_send_pos == 2)
        return_of_send_pos = send_pos(enemy_pos, pid);
}

void gameloop(char **my_pos, char **enemy_pos, int player_turn_setup, int pid)
{
    int player_turn = player_turn_setup;

    while (1) {
        my_printf("player turn = %i\n", player_turn);
        show_game_tabs(my_pos, enemy_pos);
        if (player_turn == 0)
            attack_turn(enemy_pos, pid);
        if (did_i_won() == 0)
            return ;
        if (player_turn == 0)
            player_turn = 1;
        if (player_turn == 1)
            get_pos(my_pos, pid);
        send_game_statut(my_pos, pid);
        if (player_turn == 1)
            player_turn = 0;
    }
}