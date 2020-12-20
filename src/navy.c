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

int connect_player_1(void)
{
    int enemy_pid = 0;

    my_putstr("waiting for enemy connection...\n");
    get_calling_pid();
    pause();
    enemy_pid = sig_reception;
    kill(enemy_pid, SIGUSR2);
    while (sig_reception != 2) {
        get_signal();
        pause();
    }
    my_putchar('\n');
    my_putstr("enemy connected\n\n");
    return (enemy_pid);
}

int connect_players(int pid, int player)
{
    sig_reception = 0;
    my_printf("my_pid: %i\n", getpid());
    if (player == -1)
        pid = connect_player_1();
    else {
        kill(pid, SIGUSR1);
        while (sig_reception != 2)
            get_signal();
        kill(pid, SIGUSR2);
        my_putstr("successfully connected\n\n");
    }
    return (pid);
}

void navy(char *pid, char *pos_path)
{
    char **my_pos = setup_blank_tab();
    char **enemy_pos = setup_blank_tab();
    int pid_int = my_getnbr(pid);
    int player = my_getnbr(pid);

    put_boats_in_tab(my_pos, pos_path);
    pid_int = connect_players(pid_int, player);
    if (player == -1)
        gameloop(my_pos, enemy_pos, 0, pid_int);
    if (player != -1)
        gameloop(my_pos, enemy_pos, 1, pid_int);
    return ;
}