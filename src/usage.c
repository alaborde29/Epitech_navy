/*
** EPITECH PROJECT, 2021
** B-PSU-101-NAN-1-1-navy-enzo.bonato
** File description:
** usage
*/

#include "my.h"

void usage(void)
{
    my_putstr("USAGE\n");
    my_putstr("\t./navy [first_player_pid] navy_positions\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("\tfirst_player_pid: only for the 2nd ");
    my_putstr("player. pid of the first player\n");
    my_putstr("\tnavy_positions: file ");
    my_putstr("representing the positions of the ships\n");
}