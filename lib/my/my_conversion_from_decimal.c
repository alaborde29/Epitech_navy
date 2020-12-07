/*
** EPITECH PROJECT, 2020
** conversion
** File description:
** b10 to b2
*/

#include <stdlib.h>
#include "my.h"

int decimal_to_binary(unsigned int nb)
{
    char *result = malloc((sizeof(char) * 3) + 2);
    int i = 0;

    while (nb != 0) {
        result[i] = (nb % 2) + 48;
        nb /= 2;
        i++;
    }
    my_revstr(result);
    result[i] = '\0';
    my_putstr(result);
    return 0;
}

int decimal_to_octal(int nb)
{
    char *result = malloc(sizeof(char) + 1);
    int i = 0;

    while (nb != 0) {
        result[i] = (nb % 8) + 48;
        nb /= 8;
        i++;
    }
    my_revstr(result);
    result[i] = '\0';
    my_putstr(result);
    return 0;
}

int decimal_to_hexa_min(int nb)
{
    char *result = malloc(sizeof(char));
    int i = 0;

    while (nb != 0) {
        if ((nb % 16) < 10)
            result[i] = (nb % 16) + 48;
        else if ((nb % 16) >= 10 && (nb % 16) < 16) {
            result[i] = (nb % 16) + 87;
        }
        nb /= 16;
        i++;
    }
    my_revstr(result);
    result[i] = '\0';
    my_putstr(result);
    return 0;
}

int decimal_to_hexa_maj(int nb)
{
    char *result = malloc(sizeof(char));
    int i = 0;

    while (nb != 0) {
        if ((nb % 16) < 10)
            result[i] = (nb % 16) + 48;
        else
            result[i] = (nb % 16) + 55;
        nb /= 16;
        i++;
    }
    my_revstr(result);
    result[i] = '\0';
    my_putstr(result);
    return 0;
}