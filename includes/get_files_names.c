/*
** EPITECH PROJECT, 2023
** GET_FILES_NAMES
** File description:
** get_files_names
*/

#include <dirent.h>
#include "my.h"

char **get_files_names(struct dirent *entries, char *dirpath)
{
    DIR *mydir = opendir(dirpath);
    DIR *mydir2 = opendir(dirpath);
    char **filesname;
    int nbname = get_nbname(filesname, entries, mydir);
    int lenname;

    filesname = malloc(sizeof(char *) * nbname + 1);
    filesname[nbname] = 0;
    entries = readdir(mydir2);
    for (int i = 0; entries != NULL; i++) {
        lenname = my_strlen(entries->d_name);
        filesname[i] = malloc(sizeof(char) * lenname + 1);
        filesname[i][lenname] = '\0';
        filesname[i] = entries->d_name;
        entries = readdir(mydir2);
    }
    return (filesname);
}
