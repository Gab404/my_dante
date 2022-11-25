/*
** EPITECH PROJECT, 2022
** lib.c
** File description:
** lib
*/

#include "generator.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == 'X')
            my_putchar(str[i]);
        else
            my_putchar('*');
        i++;
    }
    return 0;
}

void my_show_word_array(char **tab, int raw)
{
    for (int i = 0; i < raw; i++) {
        printf("%s", tab[i]);
        if (i < raw - 1)
            printf("\n");
    }
    return;
}

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}