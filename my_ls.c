/*
** EPITECH PROJECT, 2023
** MY_LS
** File description:
** Remake ls
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/sysmacros.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include "includes/my.h"

int make_my_ls(struct dirent *entries, char *dirpath)
{
    DIR *dir = opendir(dirpath);
    char **filesname = get_files_names(entries, dirpath);

    filesname = get_in_alpha_order(entries, dirpath, filesname);
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

int test_my_ls(struct dirent *entries, char *dirpath, char *flag)
{
    DIR *dir = opendir(dirpath);

    if (dir == NULL)
        exit(84);
    entries = readdir(dir);
    if (dir == NULL || entries == NULL) {
        write(2, "No such file or directory\n", 27);
        exit(84);
    }
    if (flag[0] == ' ')
        make_my_ls(entries, dirpath);
    if (flag[0] == 'a')
        make_my_ls_a(entries, dirpath);
    if (flag[0] == 'l')
        make_my_ls_l(entries, dirpath);
    if (flag[0] == 'r')
        make_my_ls_r(entries, dirpath);
    if (flag[0] == 't')
        make_my_ls_t(entries, dirpath);
}

static char get_flag(char *flag)
{
    if (flag[1] == 'a')
        return ('a');
    if (flag[1] == 'l')
        return ('l');
    if (flag[1] == 'r')
        return ('r');
    if (flag[1] == 't')
        return ('t');
}

void print_that(char **av, int ac, int i, char *flag)
{
    struct dirent *entries;

    if (ac > 2 && flag[0] == ' ' || (flag[0] != ' ' && ac > 3))
        mini_printf("%s:\n", av[i]);
    test_my_ls(entries, av[i], flag);
    if (i + 1 < ac && flag[0] == ' ' || (flag[0] != ' ' && i + 2 < ac))
        mini_printf("\n");
}

int main(int ac, char **av)
{
    struct dirent *entries;
    char flag[] = " ";

    for (int i = 1; i < ac; i++) {
        if (av[i][0] == '-' && is_flag(av[i]) != 1)
            error_message(av[i]);
        if (av[i][0] == '-')
            flag[0] = get_flag(av[i]);
    }
    if (ac == 1 || (ac == 2 && flag[0] != ' '))
        test_my_ls(entries, ".", flag);
    for (int i = 1; i < ac; i++) {
        if (av[i][0] != '-')
            print_that(av, ac, i, flag);
    }
}
