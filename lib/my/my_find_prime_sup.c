/*
** EPITECH PROJECT, 2020
** my_ find_p rime_sup.c
** File description:
** 1er
*/

int my_find_prime_sup(int nb)
{
    int i = 2;

    if (nb <= 1) {
        return (0);
    }
    while (i % nb > 0) {
        if (i == nb) {
            return (nb);
        }
        if (nb % i == 0) {
            nb++;
            i = 1;
        }
        i++;
    }
    return (nb);
}
