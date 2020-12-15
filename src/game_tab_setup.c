/*
** EPITECH PROJECT, 2020
** B-PSU-101-NAN-1-1-navy-enzo.bonato
** File description:
** game_tab_setup
*/

#include "my.h"
#include "navy.h"

void put_this_boat(char **array, char *boat)
{
    vector2i_t pos1 = create_vetor2i(boat[3] - '0' - 1, boat[2] - 'A');
    vector2i_t pos2 = create_vetor2i(boat[6] - '0' - 1, boat[5] - 'A');
    int boat_orientation = find_boat_orientation(boat);

    if (boat_orientation == 1) {
        if (pos2.y < pos1.y)
            my_swap(&pos2.y, &pos1.y);
        for (int n = pos1.y; n != n + boat[0] - '0'; n++)
            array[n][pos1.x] = boat[0];
    }
    if (boat_orientation == 2) {
        if (pos2.x < pos1.x)
            my_swap(&pos2.y, &pos1.y);
        for (int n = pos1.x; n != n + boat[0] - '0'; n++)
            array[pos1.y][n] = boat[0];
    }
    return ;
}

void put_boats_in_tab(char **array, char *pos_path)
{
    char *pos = 0;
    char **pos_tab = 0;

    read_file(pos_path, pos);
    pos_tab = split_lines(pos, 5);
    for (int i = 0; i != 4; i++)
        put_this_boat(array, pos_tab[i]);
    return ;
}

char **setup_blank_tab(void)
{
    char **tab = malloc(sizeof(char *) * 11);
    char stamp[11] = "X|........\0";
    for (int i = 0; i != 10; i++) {
        tab[i] = malloc(sizeof(char) * 11);
        tab[i][10] = '\0';
    }
    tab[0] = " |ABCDEFGH\0";
    tab[1] = "-+--------";
    for (int j = 2; j != 10; j++) {
        my_strdup(stamp, tab[j]);
        tab[j][0] = j - 1 + '0';
    }
    return (tab);
}