/*
** EPITECH PROJECT, 2020
** flags 2
** File description:
** printf
*/

#include <stdarg.h>
#include "my.h"

void specifier_b(va_list ap)
{
    decimal_to_binary(va_arg(ap, unsigned int));
}

void specifier_o(va_list ap)
{
    decimal_to_octal(va_arg(ap, int));
}

void specifier_x_min(va_list ap)
{
    decimal_to_hexa_min(va_arg(ap, int));
}

void specifier_x_maj(va_list ap)
{
    decimal_to_hexa_maj(va_arg(ap, int));
}

void specifier_p(va_list ap)
{
    my_putstr("0x");
    decimal_to_hexa_min(va_arg(ap, int));
}