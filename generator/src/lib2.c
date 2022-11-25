/*
** EPITECH PROJECT, 2022
** lib2.c
** File description:
** lib2
*/

#include "generator.h"

void free_tab_char(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        free(tab[i]);
    }
}

int my_strcmp(char *str, char *str_2)
{
    int len = my_strlen(str);
    int len_2 = my_strlen(str_2);


    if (len < len_2)
        return -1;
    for (int i = 0; i < len; i++) {
        if (str[i] != str_2[i])
            return -1;
    }
    return 0;
}

int my_getnbr(char const *str)
{
    int neg = 1;
    int value_0 = 48;
    int result = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '-' || str[i] == '+') {
            neg = neg * -1;
        } else if (str[i] >= '0' && str[i] <= '9') {
            result = result * 10;
            result += (str[i] - value_0);
        } else {
            return neg * result;
        }
    }
    return neg * result;
}