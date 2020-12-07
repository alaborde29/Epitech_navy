/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** my_printf
*/

#include <stdarg.h>
#include "my.h"

int flags_loop(const char *format, int *i, va_list ap)
{
    if (format[*i] == '#') {
        (*i)++;
        flags_diese(format, i);
        return 0;
    }
    if (format[*i] == ' ') {
        while (format[*i] != 'd' && format[*i] != 'i')
            (*i)++;
        flags_space(ap);
        return 0;
    }
    return 0;
}

int specifier_loop1(const char *format, int *i, va_list ap)
{
    switch (format[*i]) {
    case 'd' :
    case 'i' : specifier_d(ap); break;
    case 's' : specifier_s_min(ap); break;
    case 'c' :
    case 'C' : specifier_c(ap); break;
    case 'S' : specifier_s_maj(ap); break;
    case 'u' : specifier_u(ap); break;
    case 'o' : specifier_o(ap); break;
    case 'x' : specifier_x_min(ap); break;
    case 'X' : specifier_x_maj(ap); break;
    case 'p' : specifier_p(ap); break;
    case 'b' : specifier_b(ap); break;
    case '%' : specifier_pourcent(ap); break;
    default : my_putchar('%'); my_putchar(format[*i]);
    }
    return 0;
}

int my_printf(const char *format, ...)
{
    int specifier;
    int i = 0;

    va_list ap;
    va_start(ap, format);

    while (format[i] != 0) {
        if (format[i] == '%') {
            i++;
            flags_loop(format, &i, ap);
            specifier_loop1(format, &i, ap);
        } else
            my_putchar(format[i]);
        i++;
    }
    va_end(ap);
    return 0;
}