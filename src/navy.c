/*
** EPITECH PROJECT, 2020
** B-PSU-101-NAN-1-1-navy-enzo.bonato
** File description:
** navy
*/

#include "my.h"
#include "navy.h"
#include <sys/types.h>
#include <signal.h>

void signal_handler(int signum) {
    return ;
}

int get_signal(void)
{
    struct sigaction sa;

    sa.sa_handler = &signal_handler;
}

void connect_players(char *pid)
{
    int i = 0;

    my_printf("my_pid: %i\n", getpid());
    /*if (pid == -1) {
        my_putstr("waiting for enemy connection...\n");
        while (i != 1) {
            i = get_signal();
        }
    }
    else {
        kill(my_getnbr(pid), SIGUSR2);
    }*/
    return ;
}

void navy(char *pid, char *pos_path)
{
    char **my_pos = setup_blank_tab();
    char **enemy_pos = setup_blank_tab();

    put_boats_in_tab(my_pos, pos_path);
    my_putstr(pid);
    my_putchar('\n');
    my_show_word_array(my_pos);
    my_putchar('\n');
    my_show_word_array(enemy_pos);
    my_putchar('\n');
    return ;
}