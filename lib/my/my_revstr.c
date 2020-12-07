/*
** EPITECH PROJECT, 2020
** my_revstr.c
** File description:
** my_revstr.c
*/

char *my_revstr(char *str)
{
    int i = 0;
    int j = 0;
    int h = 0;
    char g;

    while (str[i] != '\0') {
        i++;
    }
    h = i - 1;
    while (j < i / 2) {
        g = str[j];
        str[j] = str[h];
        str[h] = g;
        j++;
        h--;
    }
    return (str);
}
