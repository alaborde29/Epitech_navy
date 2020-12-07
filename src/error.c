/*
** EPITECH PROJECT, 2020
** B-PSU-101-NAN-1-1-navy-enzo.bonato
** File description:
** error
*/

#include "my.h"
#include "navy.h"

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

char **split_lines(char *str)
{
    char **tab = malloc(sizeof(char *) * 5);
    int n = 0;
    int o = 0;
    int j = 0;
    int malloc_size = 0;

    for (int i = 0; i != 4; i++, n++, o++) {
        while (str[o] != '\n' && str[o] != '\0') {
            o++;
            malloc_size++;
        }
        tab[i] = malloc(sizeof(char) * o);
        for (; str[n] != '\n' && str[n] != '\0'; j++, n++)
            tab[i][j] = str[n];
        tab[i][j] = '\0';
        j = 0;
    }
    tab[4] = 0;
    return (tab);
}

int is_line_well_formatted(char *str, int line_pos)
{
    if (my_strlen(str) != 7)
        return (84);
    if (str[0] != (line_pos + 2 + '0'))
        return (84);
    if (str[1] != ':' || str[4] != ':')
        return (84);
    if ((str[2] < 'A' || str[2] > 'H') || (str[5] < 'A' || str[5] > 'H'))
        return (84);
    if ((str[3] < '1' || str[3] > '8') || (str[6] < '1' || str[6] > '8'))
        return (84);
    if (is_size_normal(str) == 84)
        return (84);
    return (0);
}

int is_file_content_right(char *str)
{
    char **tab = split_lines(str);

    for (int i = 0; i != 4; i++) {
        if (is_line_well_formatted(tab[i], i) == 84)
            return (84);
    }
    return (0);
}

int error(int ac, char **av)
{
    char *buffer = 0;

    if (ac != 2 && ac != 3)
        return (84);
    if (ac == 2)
        buffer = read_file(av[1], buffer);
    if (ac == 3)
        buffer = read_file(av[2], buffer);
    if (buffer == 0)
        return (84);
    if (is_file_content_right(buffer) == 84)
        return (84);
    return (0);
}