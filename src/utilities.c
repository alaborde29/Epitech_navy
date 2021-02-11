/*
** EPITECH PROJECT, 2020
** B-PSU-101-NAN-1-1-navy-enzo.bonato
** File description:
** utilities
*/

#include "my.h"
#include "navy.h"

void my_strdup(char *src, char *dest)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return ;
}

int are_str_the_same(char *str1, char *str2)
{
    int i = 0;

    if (my_strlen(str1) != my_strlen(str2))
        return (-1);
    while (str1[i] != '\0') {
        if (str1[i] != str2[i])
            return (-1);
        i++;
    }
    return (0);
}

char **split_lines(char *str, int tab_size)
{
    char **tab = malloc(sizeof(char *) * tab_size);
    int n = 0;
    int o = 0;
    int j = 0;
    int malloc_size = 0;

    for (int i = 0; i != tab_size - 1; i++, n++, o++) {
        while (str[o] != '\n' && str[o] != '\0') {
            o++;
            malloc_size++;
        }
        tab[i] = malloc(sizeof(char) * o);
        for (; str[n] != '\n' && str[n] != '\0'; j++, n++){
            tab[i][j] = str[n];}
        tab[i][j] = '\0';
        j = 0;
    }
    tab[tab_size] = 0;
    return (tab);
}

char *read_file(char *path, char *buffer)
{
    struct stat file_info;
    int st_return = stat(path, &file_info);
    int fd = open(path, O_RDONLY);
    buffer = malloc(sizeof(char) * file_info.st_size);
    int rd_return = read(fd, buffer, file_info.st_size);

    if (st_return || fd == -1 || rd_return == -1)
        return (NULL);
    else
        return (buffer);
}

vector2i_t create_vetor2i(int x, int y)
{
    vector2i_t vector;

    vector.x = x,
    vector.y = y;

    return (vector);
}