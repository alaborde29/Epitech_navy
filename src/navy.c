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

void signal_handler(int signum, siginfo_t *siginfo, void *other)
{
    int sig_reception;

    if (signum == SIGUSR1) {
        sig_reception = 1;
        return;
    }
    if (signum == SIGUSR2) {
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
    int sig_reception;

    my_putstr("waiting for enemy connection...\n");
        while (sig_reception != 1) {
            get_signal();
            sleep(1);
            my_putchar('\n');
        }
        get_calling_pid();
        kill(sig_reception, SIGUSR2);
        my_putstr("enemy connected\n");
}

void connect_players(char *pid)
{
    int sig_reception = 0;
    my_printf("my_pid: %i\n", getpid());
    if (my_getnbr(pid) == -1)
        connect_player_1(pid);
    else {
        kill(my_getnbr(pid), SIGUSR1);
        while (sig_reception = 2) {
            sleep(5);
            my_putchar('\n');
        }
        my_putstr("successfully connected\n");
    }
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