/*
** EPITECH PROJECT, 2020
** my_getnbr.c
** File description:
** getnbr
*/

#include <unistd.h>

int     my_getnbr(char const *str)
{
    int i = 0;
    int n = 0;

    if (str[0] == '-' && str[1] != '\0')
        i++;
    while (str[i] != '\0') {
        if ((str[i] < '0' || str[i] > '9')) {
            write(2, "Invalid charactere", 19);
            return (84);
        }
        n = n * 10;
        n = n + str[i] - 48;
        i++;
    }
    if (str[0] == '-')
        return (-1 * n);
    else
        return (n);
}