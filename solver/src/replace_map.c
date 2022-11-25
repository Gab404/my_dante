/*
** EPITECH PROJECT, 2022
** replace_map.c
** File description:
** replace_map
*/

#include "solver.h"

void choice_int(int **dest, int i, int k)
{
    if (dest[i][k] == 'X') {
        dest[i][k] = -1;
    } else if (dest[i][k] == '*') {
        dest[i][k] = 0;
    }
    return;
}

int **replace_map(int rows, int cols, int **dest)
{
    int i = 0;
    int k = 0;
    dest[rows - 1][cols - 1] = 1;

    while (i < rows) {
        k = 0;
        while (k < cols) {
            choice_int(dest, i, k);
            k++;
        }
        i++;
    }
    return dest;
}