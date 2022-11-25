/*
** EPITECH PROJECT, 2022
** generator.c
** File description:
** generator
*/

#include "generator.h"

void make_imperfect_maze(char **maze, int raw, int col)
{
    int y;
    int x;
    int nb_wall = (((raw * col) / 2) / 2) / 2;

    for (int k = 0; k < nb_wall / 2; k++) {
        y = rand() % (raw - 1) + 0;
        x = rand() % (col - 1) + 0;
        while (maze[y][x] != 'X') {
            y = rand() % (raw - 1) + 0;
            x = rand() % (col - 1) + 0;
        }
        maze[y][x] = '*';
    }
}

void make_last_line(int raw, int col, char **maze)
{
    int y;
    int x;

    if (raw % 2 != 0) {
        y = raw - 1;
        x = 0;
        while (x < col) {
            merge_cell(maze, x, y);
            x += 2;
        }
    }
    return;
}

char **generator(int col, int raw, int ac)
{
    char **maze = malloc(sizeof(char *) * raw + 1);

    create_grid(raw, col, maze);
    connect_cell(maze, raw, col);
    make_last_line(raw, col, maze);
    maze[0][1] = '*';
    maze[raw - 1][col - 1] = '*';
    if (ac == 2)
        make_imperfect_maze(maze, raw, col);
    return maze;
}

int main(int ac, char **av)
{
    char **maze;
    int error = gest_error(ac, av);

    srand(time(NULL));
    if (error != -1) {
        maze = generator(my_getnbr(av[1]), my_getnbr(av[2]), ac - 1);
        my_show_word_array(maze, my_getnbr(av[2]));
    } else
        return 84;
    free_tab_char(maze);
    return 0;
}