/*
** EPITECH PROJECT, 2020
** flags
** File description:
** my_printf
*/

#include <stdarg.h>
#include "my.h"

int flags_diese(const char *format, int *i)
{
    switch (format[*i]) {
    case 'x' : my_putstr("0x"); break;
    case 'X' : my_putstr("0X"); break;
    case 'o' : my_putstr("0"); break;
    case 'b' : my_putstr("0b"); break;
    }
    return 0;
}

int flags_space(va_list ap)
{
    va_list ap_copy;
    va_copy(ap_copy, ap);
    int nb = (va_arg(ap_copy, int));

    if (nb >= 0)
        my_putchar(' ');
    return 0;
}