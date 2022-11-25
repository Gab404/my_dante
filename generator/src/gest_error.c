/*
** EPITECH PROJECT, 2022
** gest_error.c
** File description:
** gest_error
*/

#include "generator.h"

void display_error(char *str)
{
    int len = my_strlen(str);

    write(2, str, len);
}

int return_good_char(char c)
{
    if (c < 48 || c > 57)
        return -1;
    return 0;
}

int check_char(int nb_arg, char **av)
{
    int good_char = 0;

    for (int i = 0; i < 2 && good_char == 0; i++) {
        for (int j = 0; av[i][j] != '\0' && good_char == 0; j++) {
            good_char = return_good_char(av[i][j]);
        }
    }
    if (nb_arg == 3 && my_strcmp(av[2], "perfect") != 0)
        return -1;
    return good_char;
}

int gest_error(int ac, char **av)
{
    int error;

    av += 1;
    if (ac > 4 || ac < 3) {
        display_error("Too few or too much argument's'\n");
        return -1;
    } else {
        error = check_char(ac - 1, av);
        if (error == -1) {
            display_error("Wrong argument format\n");
            return -1;
        }
        if (my_getnbr(av[0]) < 2 || my_getnbr(av[1]) < 2) {
            display_error("Size too small\n");
            return -1;
        }
    }
    return error;
}