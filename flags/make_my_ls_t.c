/*
** EPITECH PROJECT, 2023
** B-PSU-100-STG-1-1-myls-raphael.petrequin
** File description:
** make_my_ls_t
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/sysmacros.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include "../includes/my.h"

int comp(const char *filename1, const char *filename2)
{
    struct stat stat1;
    struct stat stat2;

    if (lstat(filename1, &stat1) == -1 || lstat(filename2, &stat2) == -1)
        return 0;
    if (stat1.st_mtime > stat2.st_mtime)
        return 1;
    else if (stat1.st_mtime < stat2.st_mtime)
        return 0;
    return 0;
}

void boubouboutest(char **str, int *j, int *j_min)
{
    if (comp(str[*j], str[*j_min]) == 1)
        *j_min = *j;
}

char **sort_str(char **str, int length)
{
    char temp[512];
    int j_min;

    for (int i = 0; i < length; i++) {
        j_min = i;
        for (int j = i + 1; j < length; j++)
            boubouboutest(str, &j, &j_min);
        if (j_min != i) {
            my_strcpy(temp, str[i]);
            my_strcpy(str[i], str[j_min]);
            my_strcpy(str[j_min], temp);
        }
    }
    return str;
}

int my_chareelen(char **charee)
{
    int i;

    for (i = 0; charee[i] != NULL; i++);
    return i;
}

int make_my_ls_t(struct dirent *entries, char *dirpath)
{
    DIR *dir = opendir(dirpath);
    char **filesname = get_files_names(entries, dirpath);
    int lencharee = my_chareelen(filesname);

    if (dir == NULL)
        exit(84);
    filesname = sort_str(filesname, lencharee);
    entries = readdir(dir);
    for (int curr = 0; entries != NULL; curr++) {
        if (filesname[curr][0] != '.')
            mini_printf("%s", filesname[curr]);
        entries = readdir(dir);
        if (entries != NULL && filesname[curr][0] != '.')
            mini_printf("  ");
    }
    mini_printf("\n");
}
