/*
** EPITECH PROJECT, 2020
** my_put_nbr.c
** File description:
** chiffre
*/

void my_putchar(char c);
int my_put_nbr(int nb)
{
    int c;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb >= 0) {
        if (nb >= 10) {
            c = (nb % 10);
            nb = (nb - c) / 10;
            my_put_nbr(nb);
            my_putchar(48 + c);
        }
        else
            my_putchar(48 + nb % 10);
    }
}
