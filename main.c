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
    if (error(ac, av) == 84)
        return (84);
    else
        printf("Yes we did it\n");
    return (0);
}