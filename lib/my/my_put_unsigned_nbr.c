/*
** EPITECH PROJECT, 2020
** unsigned int
** File description:
** lib
*/

int my_putchar(char c);

int my_put_unsigned_nbr(unsigned int nb)
{
    int c;

    if (nb >= 0) {
        if (nb >= 10) {
            c = (nb % 10);
            nb = (nb - c) / 10;
            my_put_unsigned_nbr(nb);
            my_putchar(48 + c);
        } else
            my_putchar(48 + nb % 10);
    }
}
