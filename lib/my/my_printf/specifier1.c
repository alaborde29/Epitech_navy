/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** flags
*/

#include <stdarg.h>
#include <stddef.h>
#include "my.h"

void specifier_d(va_list ap)
{
    my_put_nbr(va_arg(ap, int));
}

void specifier_s_min(va_list ap)
{
    my_putstr(va_arg(ap, char *));
}

void specifier_c(va_list ap)
{
    my_putchar(va_arg(ap, int));
}

int specifier_s_maj(va_list ap)
{
    char *str = va_arg(ap, char *);

    if (str == NULL) {
        my_putstr("(null)");
        return 0;
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] <= 7)
            my_printf("\\00%d", str[i]);
        if (str[i] > 7 && str[i] < 32) {
            my_printf("\\0%o", str[i]);
        }
        if (str[i] == 127)
            my_putstr("\\177");
        if (str[i] >= 32 && str[i] <= 126)
            my_putchar(str[i]);
    }
    return 0;
}

void specifier_u(va_list ap)
{
    my_put_unsigned_nbr(va_arg(ap, unsigned int));
}
