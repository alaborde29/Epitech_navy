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

void show_game_tabs(char **my_pos, char **enemy_pos)
{
    my_putstr("my positions:");
    my_show_word_array(my_pos);
    my_putchar('\n');
    my_putstr("enemy's positions:");
    my_show_word_array(enemy_pos);
    my_putchar('\n');
}

void gameloop(char **my_pos, char **enemy_pos, int player_turn)
{
    int return_of_send_pos = 2;
    int player_turn = 0;

    while (is_game_finished(my_pos, enemy_pos) != 1) {
        show_game_tabs(my_pos, enemy_pos);
        while (return_of_send_pos == 2 && player_turn == 0)
            return_of_send_pos = send_pos(enemy_pos);
        return_of_send_pos = 2;
        player_turn = 1;
        get_pos(my_pos);
    }
}