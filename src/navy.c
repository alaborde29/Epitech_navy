/*
** EPITECH PROJECT, 2020
** B-PSU-101-NAN-1-1-navy-enzo.bonato
** File description:
** navy
*/

#include "my.h"
#include "navy.h"

void navy(char *pid, char *pos_path)
{
    my_putchar('1');
    char **my_pos = setup_blank_tab();
    my_putchar('2');
    char **enemy_pos = setup_blank_tab();
my_putchar('3');
    put_boats_in_tab(my_pos, pos_path);
    my_putchar('4');
    my_putstr(pid);
    /*my_putchar('\n');
    my_show_word_array(my_pos);
    my_putchar('\n');
    my_show_word_array(enemy_pos);
    my_putchar('\n');*/
    return ;
}