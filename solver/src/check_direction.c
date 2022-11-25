/*
** EPITECH PROJECT, 2022
** check_direction.c
** File description:
** check_direction
*/

#include "solver.h"

int *check_up(int distance, int *pos, int **dest, bool *direction_found)
{
    int x = pos[0];
    int y = pos[1];

    if (y - 1 >= 0 && dest[y - 1][x] == 0) {
        dest[y - 1][x] = distance;
        y--;
        pos[1] = y;
        *direction_found = true;
        return pos;
    }
    pos[1] = y;
    return pos;
}

int *check_left(int distance, int *pos, int **dest, bool *direction_found)
{
    int x = pos[0];
    int y = pos[1];

    if (x - 1 >= 0 && dest[y][x - 1] == 0 && *direction_found == false) {
        dest[y][x - 1] = distance;
        x--;
        pos[0] = x;
        *direction_found = true;
        return pos;
    }
    pos[0] = x;
    return pos;
}

int *check_right_down(int *pos, int **dest, bool *found, int rows)
{
    int x = pos[0];
    int y = pos[1];
    int distance = pos[2];
    int cols = pos[3];

    if (pos[0] + 1 < cols && dest[pos[1]][pos[0] + 1] == 0 && *found == false) {
        dest[pos[1]][pos[0] + 1] = distance;
        x++;
        pos[0] = x;
        *found = true;
    }
    if (y + 1 < rows && dest[y + 1][x] == 0 && *found == false) {
        dest[y + 1][x] = distance;
        y++;
        pos[1] = y;
        *found = true;
    }
    return pos;
}


int **check_direction(int rows, int cols, int **dest)
{
    int *pos = malloc(sizeof(int) * 4);
    int distance = 2;
    bool found = false;

    pos[0] = cols - 1;
    pos[1] = rows - 1;
    pos[2] = distance;
    pos[3] = cols;
    while (dest[0][0] == 0) {
        pos = check_up(distance, pos, dest, &found);
        pos = check_left(distance, pos, dest, &found);
        pos = check_right_down(pos, dest, &found, rows);
        if (found == false)
            backtracking(pos, dest, cols, rows);
        distance++;
        pos[2] = distance;
        found = false;
    }
    return dest;
}