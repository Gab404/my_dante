/*
** EPITECH PROJECT, 2022
** create_maze.c
** File description:
** create_maze
*/

#include "generator.h"

void merge_cell(char **maze, int x, int y)
{
    int random_cell = rand() % 2 + 1;

    if (random_cell == 1 && y > 0) {
        maze[y - 1][x] = maze[y][x];
    } else {
        random_cell = 2;
    }

    if (random_cell == 2 && x > 0) {
        maze[y][x - 1] = maze[y][x];
    } else if (y > 0)
        maze[y - 1][x] = maze[y][x];
    return;
}

void connect_cell(char **maze, int raw, int col)
{
    int y = 0;
    int x = 0;

    for (int i = 0; i > -1; i++) {
        if (x >= col) {
            x = 0;
            y += 2;
        }
        if (y >= raw - 1)
            return;
        merge_cell(maze, x, y);
        x += 2;
    }
    return;
}

char choice_char(int change_fill, int nb_raw, int raw)
{
    if (change_fill % 2 == 0 && nb_raw != raw - 1) {
        return '*';
    } else if (nb_raw == raw - 1 && change_fill % 2 == 0)
        return '*';
    else
        return 'X';
}

char fill_init_maze(int change_fill, int nb_raw, int nb_col, int raw)
{
    char c;

    if ((nb_raw % 2 == 0 && nb_col % 2 == 0) || nb_raw == raw - 1)
        c = choice_char(change_fill, nb_raw, raw);
    else
        c = 'X';

    return c;
}