/*
** EPITECH PROJECT, 2020
** B-PSU-101-NAN-1-1-navy-enzo.bonato
** File description:
** base_convertion
*/

#include "my.h"
#include "navy.h"

int decimal_to_binary(int nb)
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

int binary_to_decimal(unsigned int nb)
{

    return (0);
}