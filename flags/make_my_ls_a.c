/*
** EPITECH PROJECT, 2023
** MAKE_MY_LS_A
** File description:
** make_my_ls_a
*/

#include <stddef.h>
#include "../includes/my.h"

int make_my_ls_a(struct dirent *entries, char *dirpath)
{
    DIR *dir = opendir(dirpath);
    char **filesname = get_files_names(entries, dirpath);

    filesname = get_in_alpha_order(entries, dirpath, filesname);
    entries = readdir(dir);
    for (int curr = 0; entries != NULL; curr++) {
        mini_printf("%s", filesname[curr]);
        entries = readdir(dir);
        if (entries != NULL)
            mini_printf("  ");
    }
    mini_printf("\n");
}
