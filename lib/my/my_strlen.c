/*
** EPITECH PROJECT, 2020
** my_strlen.c
** File description:
** nombre de lettre
*/

int my_strlen(char const * str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}
