/*
** EPITECH PROJECT, 2022
** create_maze_with_way.c
** File description:
** create_maze_with_way
*/

#include "solver.h"

void choice_char(int **check, int i, int j, char **maze)
{
    if (check[i][j] == -1)
        maze[i][j] = 'X';
    else if (check[i][j] == 0)
        maze[i][j] = '*';
    else
        maze[i][j] = 'o';
    return;
}

char **create_maze_with_way(int **check, int rows, int cols)
{
    int i = 0;
    int j = 0;
    char **maze = malloc(sizeof(char *) * (rows + 1));

    while (i != rows) {
        maze[i] = malloc(sizeof(char) * cols);
        while (j != cols) {
            choice_char(check, i, j, maze);
            j++;
        }
        i++;
        j = 0;
    }
    maze[rows] = NULL;
    return maze;
}