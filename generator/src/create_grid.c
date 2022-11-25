/*
** EPITECH PROJECT, 2022
** create_grid.c
** File description:
** create_grid
*/

#include "generator.h"

void set_change_fill(int nb_raw, int raw, int j, int *change_fill)
{
    if (nb_raw == raw - 1 && j == 0 && raw % 2 == 0)
        *change_fill += 1;
    return;
}

void create_grid(int raw, int col, char **maze)
{
    int nb_col = 0;
    int nb_raw = 0;
    int change_fill = 0;
    int reset_change_fill = 1;

    for (int i = 0; i < raw; i++) {
        maze[i] = malloc(sizeof(char) * col + 1);
        for (int j = 0; j < col; j++) {
            set_change_fill(nb_raw, raw, j, &change_fill);
            maze[i][j] = fill_init_maze(change_fill, nb_raw, nb_col, raw);
            change_fill++;
            nb_col++;
        }
        nb_col = 0;
        nb_raw++;
        change_fill = reset_change_fill;
        reset_change_fill++;
        maze[i][col] = '\0';
    }
}