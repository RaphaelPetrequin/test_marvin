/*
** EPITECH PROJECT, 2023
** GET_IN_REV_ALPHA_ORDER
** File description:
** get_in_rev_alpha_order
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int cmp_rev(char **fname, int index, int j)
{
    if (strchcmp(fname[index], fname[j]) == 1)
        index = j;
    return (index);
}

char **get_rev_alphorder(struct dirent *entries, char *dirpath, char **fname)
{
    DIR *dir = opendir(dirpath);
    int size = get_nbname(fname, entries, dir);
    int index;
    int j;
    char *tmp;

    for (int i = 0; i < size - 1; i++) {
        index = i;
        for (j = i + 1; j < size; j++) {
            index = cmp_rev(fname, index, j);
        }
        if (index != i) {
            tmp = fname[i];
            fname[i] = fname[index];
            fname[index] = tmp;
        }
    }
    return (fname);
}
