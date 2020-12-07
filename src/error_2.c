/*
** EPITECH PROJECT, 2020
** B-PSU-101-NAN-1-1-navy-enzo.bonato
** File description:
** error_2
*/

#include "my.h"
#include "navy.h"

int find_boat_orientation(char *str)
{
    if (str[2] == str[5])
        return (2);
    if (str[3] == str[6])
        return (1);
    if ((str[2] != str[5]) && (str[3] != str[6]))
        return (84);
    return (0);
}

int is_size_normal(char *str)
{
    int orientation = find_boat_orientation(str);
    int size = 0;

    if (orientation == 84)
        return (84);
    if (orientation == 1)
        size = str[5] - str[2];
    if (orientation == 2)
        size = str[6] - str[3];
    if (size < 0)
        size = size * -1 + 1;
    else
        size = size + 1;
    if (size != str[0] - '0')
        return (84);
    return (0);
}