/*
** EPITECH PROJECT, 2021
** generator.h
** File description:
** generator
*/

#ifndef GENERATOR_H_
    # define GENERATOR_H_

    #include <stdbool.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <time.h>

void create_grid(int raw, int col, char **maze);
void merge_cell(char **maze, int x, int y);
int my_strcmp(char *str, char *str_2);
int **convert_to_int(char **maze, int raw, int col);
void connect_cell(char **maze, int raw, int col);
char fill_init_maze(int change_fill, int nb_raw, int nb_col, int raw);
void free_tab_char(char **tab);
void my_show_word_array(char **tab, int raw);
int gest_error(int ac, char **av);
int my_strlen(char *str);
int my_getnbr(char const *str);


#endif /* GENERATOR_H_ */
