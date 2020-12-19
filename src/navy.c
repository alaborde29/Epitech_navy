/*
** EPITECH PROJECT, 2020
** B-PSU-101-NAN-1-1-navy-enzo.bonato
** File description:
** navy
*/

#include "my.h"
#include "navy.h"
#include <sys/types.h>
#include <sys/sysinfo.h>

int sig_reception;

void signal_handler(int signum, siginfo_t *siginfo, void *other)
{
    if (signum == SIGUSR1) {
        my_putstr("sigusr1\n");
        sig_reception = 1;
        return;
    }
    if (signum == SIGUSR2) {
        my_putstr("sigusr1\n");
        sig_reception = 2;
        return;
    }
    return ;
}

int get_signal(void)
{
    struct sigaction sa;

    sa.sa_sigaction = &signal_handler;
    sa.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
}

void connect_player_1(char *pid)
{
    my_putstr("waiting for enemy connection...\n");
        while (sig_reception != 1) {
            my_putchar('a');
            my_put_nbr(sig_reception);
            get_signal();
            sleep(5);
            my_putchar('\n');
        }
        my_putchar('b');
        get_calling_pid();
        my_putchar('c');
        kill(sig_reception, SIGUSR2);
        my_putchar('d');
        my_putstr("enemy connected\n");
        my_putchar('e');
}

void connect_players(char *pid)
{
    sig_reception = 0;
    my_printf("my_pid: %i\n", getpid());
    if (my_getnbr(pid) == -1)
        connect_player_1(pid);
    else {
        my_putchar('1');
        kill(my_getnbr(pid), SIGUSR1);
        my_putchar('2');
        while (sig_reception != 2) {
            my_putchar('3');
            get_signal();
            my_putchar('4');
            sleep(5);
            my_putchar('\n');
        }
        my_putstr("successfully connected\n");
    }
    my_put_nbr(sig_reception);
    return ;
}

void navy(char *pid, char *pos_path)
{
    char **my_pos = setup_blank_tab();
    char **enemy_pos = setup_blank_tab();

    put_boats_in_tab(my_pos, pos_path);
    connect_players(pid);
    return ;
}