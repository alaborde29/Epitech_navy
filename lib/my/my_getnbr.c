/*
** EPITECH PROJECT, 2020
** my_getnbr.c
** File description:
** getnbr
*/

#include <unistd.h>

int my_str_isnum(char const *str);

int my_isnum(char const *str)
{
    int i = 0;
    int counter_nb = 0;

    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            counter_nb++;
        } else if (str[i] == '+' || str[i] == '-') {
        } else {
            break;
        }
        i++;
    }
    if (counter_nb > 0) {
        return (0);
    } else
        return (1);
}

int error(long long nb, char const *str, int i)
{
    if (nb >= 2147483647 || nb <= -2147483648) {
        write(2, ("The number doesn 't fit in an integer"), 37);
        return (84);
    }
    if (str[i] == ('\0') && my_str_isnum(str) == 0) {
        write(2, ("There is no digits"), 18);
        return (84);
    }
}

int check_if_negative(char const *str, int i, int nb, int counter)
{
    while (str[i] != ('\0') && (str[i] < '0' || str[i] > '9')) {
        if (str[i] == ('-')) {
            counter++;
        }
        i++;
    }
    while (counter != (1) || counter != (0)) {
        counter = counter % 2;
        if (counter == 1) {
            return (1);
        } else {
            return (0);
        }
    }
}

int my_getnbr(char const *str)
{
    int i = 0;
    int counter = 0;
    long long nb = 0;

    while (str[i] < '0' || str[i] > '9')
        i++;
    while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9')) {
        if (str[i] >= '0' && str[i] <= '9')
            nb = nb * 10 + (str[i] - 48);
        i++;
    }
    if (error(nb, str, i) == 84)
        return (84);
    if (my_isnum(str) == 1)
        return (0);
    if (check_if_negative(str, 0, nb, counter) == 1) {
        return (nb * (-1));
    } else
        return (nb);
}
