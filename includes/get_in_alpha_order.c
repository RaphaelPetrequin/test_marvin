/*
** EPITECH PROJECT, 2023
** PRINT_IN_ALPHA_ORDER
** File description:
** prints a list in alpha order
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int cmp(char **fname, int index, int j)
{
    if (strchcmp(fname[index], fname[j]) == 2)
        index = j;
    return (index);
}

char **get_in_alpha_order(struct dirent *entries, char *dirpath, char **fname)
{
    DIR *dir = opendir(dirpath);
    int size = get_nbname(fname, entries, dir);
    int index;
    int j;
    char *tmp;

    for (int i = 0; i < size - 1; i++) {
        index = i;
        for (j = i + 1; j < size; j++) {
            index = cmp(fname, index, j);
        }
        if (index != i) {
            tmp = fname[i];
            fname[i] = fname[index];
            fname[index] = tmp;
        }
    }
    return (fname);
}
