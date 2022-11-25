/*
** EPITECH PROJECT, 2022
** solver.h
** File description:
** solver
*/

#include "solver.h"

int **mem_alloc_2d_array(int nb_rows, int nb_cols)
{
    int i = 0;
    int **tab;
    tab = malloc(sizeof(int *) * nb_rows);

    while (i < nb_rows) {
        tab[i] = malloc(sizeof(int) * (nb_cols + 1));
        i++;
    }
    return (tab);
}


int **load_2d_array_in_mem(int nb_rows, int nb_cols, char *tab)
{
    int **dest = mem_alloc_2d_array(nb_rows, nb_cols);
    int i = 0;
    int e = 0;
    int k = 0;

    while (i < nb_rows) {
        while (k != nb_cols && tab[e] != '\n') {
            dest[i][k] = tab[e];
            k++;
            e++;
        }
        k = 0;
        e++;
        i++;
    }
    return dest;
}

void backtracking(int *pos, int **dest, int cols, int rows)
{
    bool v = true;

    if (pos[1] - 1 >= 0 && UP != 0 && UP != -1 && v) {
        pos[1]--;
        v = false;
    }
    if (pos[0] - 1 >= 0 && LEFT != 0 && LEFT != -1 && v) {
        pos[0]--;
        v = false;
    }
    if (pos[0] + 1 < cols && RIGHT != 0 && RIGHT != -1 && v) {
        pos[0]++;
        v = false;
    }
    if (pos[1] + 1 < rows && DOWN != 0 && DOWN != -1 && v) {
        pos[1]++;
        v = false;
    }
    return;
}

int main(int ac, char **av)
{
    char *str = load_file(av[1]);
    int rows;
    int cols;
    int **tab;
    int **check;
    char **maze;

    if (str == NULL)
        return 84;
    rows = my_strlen_line(str);
    cols = my_strlen_column(str);
    tab = load_2d_array_in_mem(rows, cols, str);
    replace_map(rows, cols, tab);
    check = check_direction(rows, cols, tab);
    maze = create_maze_with_way(check, rows, cols);
    my_show_word_array(maze);
    return 0;
}
