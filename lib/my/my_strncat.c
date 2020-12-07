/*
** EPITECH PROJECT, 2020
** my_strncat.c
** File description:
** 3
*/

int my_strlen(char const *str);

char *my_strncat(char *dest, char const *src, int nb)
{
    int i;
    int j = 0;

    i = my_strlen(dest);
    while (src[j] != '\0' && i != nb) {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    return (dest);
}
