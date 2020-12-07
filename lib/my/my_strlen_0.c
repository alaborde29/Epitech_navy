/*
** EPITECH PROJECT, 2020
** my_strlen_0.c
** File description:
** count the 0 
*/

int my_strlen_0(char const * str)
{
    int i = 0;

    while (str[i] == '\0') {
        i++;
    }
    return (i);
}
