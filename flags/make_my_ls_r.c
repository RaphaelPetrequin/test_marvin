/*
** EPITECH PROJECT, 2023
** MAKE_MY_LS_R
** File description:
** make_my_ls_r
*/

#include <stddef.h>
#include "../includes/my.h"

int make_my_ls_r(struct dirent *entries, char *dirpath)
{
    DIR *dir = opendir(dirpath);
    char **filesname = get_files_names(entries, dirpath);

    filesname = get_rev_alphorder(entries, dirpath, filesname);
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
