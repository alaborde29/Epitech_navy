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

char **split_lines(char *str, int tab_size)
{
    char **tab = malloc(sizeof(char *) * tab_size);
    int n = 0;
    int o = 0;
    int j = 0;
    int malloc_size = 0;

    my_putchar('a');
    for (int i = 0; i != tab_size - 1; i++, n++, o++) {
        while (str[o] != '\n' && str[o] != '\0') {
            my_putchar('b');
            o++;
            malloc_size++;
        }
        my_putchar('c');
        tab[i] = malloc(sizeof(char) * o);
        my_putchar('f');
        for (; str[n] != '\n' && str[n] != '\0'; j++, n++){
            my_putchar('e');
            tab[i][j] = str[n];}
        my_putchar('f');
        tab[i][j] = '\0';
        my_putchar('g');
        j = 0;
        my_putchar('h');
    }
    my_putchar('i');
    tab[tab_size] = 0;
    my_putchar('j');
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
        return (0);
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