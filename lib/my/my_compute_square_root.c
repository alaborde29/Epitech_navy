/*
** EPITECH PROJECT, 2020
** my_compute_square_root.c
** File description:
** square_root
*/

int my_compute_square_root(int nb)
{
    int result = 1;
    int i = 1;

    while (result <= nb) {
        result = i * i;
        if (result == nb) {
            return (i);
        }
        i++;
    }
    return (0);
}
