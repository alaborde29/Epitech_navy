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
#include <unistd.h>

void put_info_in_str(char *pos, int letter, int number)
{
    pos[0] = letter + 'A' - 2;
    pos[1] = number + '0' - 1;
    pos[2] = '\0';
    sig_reception = 1;
}

char *get_pos_from_enemy(void)
{
    int letter = 0;
    int number = 0;
    char *pos = malloc(sizeof(char) * 3);

    while (sig_reception != 2) {
        get_signal();
        pause();
        letter++;
    }
    sig_reception = 0;
    while (sig_reception != 2) {
        get_signal();
        pause();
        number++;
    }
    put_info_in_str(pos, letter, number);
    return (pos);
}

void send_pos_to_enemy(char *pos, int pid)
{
    int i = 0;

    while (i != pos[0] - 'A' + 1) {
        kill(pid, SIGUSR1);
        usleep(15000);
        i++;
    }
    kill(pid, SIGUSR2);
    usleep(15000);
    i = 0;
    while (i != pos[1] - '0') {
        kill(pid, SIGUSR1);
        usleep(15000);
        i++;
    }
    kill(pid, SIGUSR2);
    usleep(15000);
}