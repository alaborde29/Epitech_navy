/*
** EPITECH PROJECT, 2020
** my_strcat.c
** File description:
** 2
*/

int my_strlen(char const *str);
char *my_strcat(char *dest, char const *src)
{
    int i;
    int j = 0;

    i = my_strlen(dest);
    while (src[j] != '\0') {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    return (dest);
}
