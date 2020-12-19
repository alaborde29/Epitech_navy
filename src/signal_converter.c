/*
** EPITECH PROJECT, 2020
** B-PSU-101-NAN-1-1-navy-enzo.bonato
** File description:
** signal_converter
*/

#include "my.h"
#include "navy.h"
#include <sys/types.h>
#include <sys/sysinfo.h>
#include <stdio.h>

char *get_pos_from_enemy(void)
{
    int letter = 0;
    int number = 0;
    char *pos = malloc(sizeof(char) * 3);

    while (sig_reception != 2) {
        get_signal();
        letter++;
    }
    sig_reception = 0;
    while (sig_reception != 2) {
        get_signal();
        number++;
    }
    pos[0] = letter + 'A';
    pos[1] = number + '0';
    pos[2] = '\0';
    sig_recception = 1;
    return (pos);
}

int send_pos_to_enemy(char *pos)
{
    int i = 0;

    
}