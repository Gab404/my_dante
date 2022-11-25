/*
** EPITECH PROJECT, 2022
** basic_functions.c
** File description:
** basic_functions
*/

#include "solver.h"

void display_error(char *str)
{
    int len = my_strlen_column(str);

    write(2, str, len + 1);
}

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return 0;
}

char *my_strcpy(char *dest, char const *src)
{
    int i;

    i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i = i + 1;
        dest[i] = '\0';
    }
    return (dest);
}

int my_strlen_column(char const *str)
{
    int i = 0;

    while (str[i] != '\n')
        i++;
    return (i);
}
