/*
** EPITECH PROJECT, 2020
** my_str_isprintable.c
** File description:
** str_isprintable
*/

int my_str_isprintable(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 32 && str[i] <= 126) {
            i++;
        }
        else
            return (0);
    }
    return ('1');
}
