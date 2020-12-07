/*
** EPITECH PROJECT, 2020
** my_strcmp.c
** File description:
** strcmp
*/

int my_strcmp(char const *s1, char const *s2)
{
    for (int i = 0; s1[i] != '\0' || s2[i] != '\0'; i++) {
        if (s1[i] < s2[i])
            return (-1);
        if (s1[i] > s2[i])
            return (1);
    }
    return (0);
}
