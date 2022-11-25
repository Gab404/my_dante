/*
** EPITECH PROJECT, 2022
** lib.c
** File description:
** lib
*/

#include "solver.h"

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    if (nb >= 10) {
        my_put_nbr(nb / 10);
        my_putchar(nb % 10 + '0');
    }
    if (nb < 10) {
        my_putchar(nb + '0');
    }
    return nb;
}

int my_strlen_line(char *const str)
{
    int i = 0;
    int k = 1;

    while (str[i] != '\0') {
        if (str[i] == '\n') {
            k++;
        }
        i++;
    }
    return k;
}

char *check_return_read(int return_read, char *str)
{
    if (return_read == -1) {
        display_error("Read failded\n");
        return NULL;
    } else if (return_read == 0) {
        display_error("File is empty\n");
        return NULL;
    }
    return str;
}

void my_show_word_array(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        if (tab[i + 1] != NULL)
            printf("%s\n", tab[i]);
        else
            printf("%s", tab[i]);
    }
    return;
}

char *load_file(char *const filepath)
{
    int fd = open(filepath, O_RDONLY);
    char *str;
    struct stat buf;
    int return_read;

    if (fd < 0) {
        display_error("Open failed\n");
        return NULL;
    }
    stat(filepath, &buf);
    str = malloc(sizeof(char) * buf.st_size);
    my_strcpy(str, filepath);
    return_read = read(fd, str, buf.st_size);
    close(fd);
    str = check_return_read(return_read, str);
    return str;
}