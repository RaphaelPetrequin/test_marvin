/*
** EPITECH PROJECT, 2023
** GET_NBNAME
** File description:
** get_nbname
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int get_nbname(char **filesname, struct dirent *entries, DIR *mydir)
{
    int nbname = 0;

    entries = readdir(mydir);
    while (entries != NULL) {
        nbname++;
        entries = readdir(mydir);
    }
    return (nbname);
}
