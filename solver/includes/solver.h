/*
** EPITECH PROJECT, 2021
** solver.h
** File description:
** solver
*/

#ifndef SOLVER_H_
    # define SOLVER_H_

    #define UP dest[pos[1] - 1][pos[0]]
    #define LEFT dest[pos[1]][pos[0] - 1]
    #define RIGHT dest[pos[1]][pos[0] + 1]
    #define DOWN dest[pos[1] + 1][pos[0]]

    #include <stdbool.h>
    #include <unistd.h>
    #include <string.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>

void backtracking(int *pos, int **dest, int cols, int rows);
int **replace_map(int rows, int cols, int **dest);
int **check_direction(int rows, int cols, int **dest);
char **create_maze_with_way(int **check, int rows, int cols);
void my_show_word_array(char **tab);
void display_error(char *str);
int my_put_nbr(int nb);
int my_putstr(char const *str);
void my_putchar(char c);
char *my_strcpy(char *dest, char const *src);
int my_strlen_column(char const *str);
char *load_file(char *const filepath);
int my_strlen_line(char *const str);

#endif /* SOLVER_H_ */
