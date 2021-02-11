/*
** EPITECH PROJECT, 2020
** navi
** File description:
** main
*/

#include "my.h"
#include "navy.h"

int main(int ac, char **av)
{
    if (ac == 2 && are_str_the_same(av[1], "-h") == 0) {
        usage();
        return (0);
    }
    if (error_navy(ac, av) == 1)
        return (84);
    if (ac == 2)
        navy("-1", av[1]);
    if (ac == 3)
        navy(av[1], av[2]);
    return (0);
}