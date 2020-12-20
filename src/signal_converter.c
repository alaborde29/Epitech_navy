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

char *get_pos_from_enemy(void)
{
    int letter = 0;
    int number = 0;
    char *pos = malloc(sizeof(char) * 3);

    my_putchar('U');
    my_put_nbr(sig_reception);
    while (sig_reception != 2) {
        my_putchar('+');
        get_signal();
        pause();
        my_put_nbr(sig_reception);
        letter++;
    }
    my_put_nbr(letter);
    my_putchar('V');
    sig_reception = 0;
    my_putchar('M');
    while (sig_reception != 2) {
        get_signal();
        pause();
        number++;
    }
    my_putchar('\n');
    my_put_nbr(letter);
    my_putchar('\n');
    my_putchar('\n');
    my_put_nbr(number);
    my_putchar('\n');
    my_putchar('W');
    pos[0] = letter + 'A' - 1;
    pos[1] = number + '0' - 1;
    pos[2] = '\0';
    sig_reception = 1;
    return (pos);
}

int send_pos_to_enemy(char *pos, int pid)
{
    int i = 0;

    while (i != pos[0] - 'A' + 1) {
        my_putchar('-');
        kill(pid, SIGUSR1);
        usleep(15000);
        i++;
    }
    kill(pid, SIGUSR2);
    usleep(15000);
    i = 0;
    my_putchar('\n');
    my_putstr("pos letter :");
    my_put_nbr(pos[0] - 'A' + 1);
    my_putchar('\n');
    my_putchar('\n');
    my_putstr("pos number :");
    my_put_nbr(pos[1] - '0');
    my_putchar('\n');
    while (i != pos[1] - '0') {
        my_putchar('o');
        kill(pid, SIGUSR1);
        usleep(15000);
        i++;
    }
    kill(pid, SIGUSR2);
    usleep(15000);
}