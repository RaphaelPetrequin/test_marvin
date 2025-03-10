/*
** EPITECH PROJECT, 2023
** INFO_FILE
** File description:
** Displays inf of a file
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/sysmacros.h>
#include <dirent.h>
#include <unistd.h>
#include "my.h"

int search_name(char *av)
{
    char name[100];
    int index = my_strlen(av) - 1;
    int i = 0;

    for (index; av[index - 1] != '/' && index > 0; index--) {
    }
    for (int i = 0; av[index] != '\0'; i++) {
        name[i] = av[index];
        index++;
    }
    name[index] = '\0';
    mini_printf("Name: %s\n", name);
    return (0);
}

int search_type(struct stat *buf)
{
    if (S_ISREG(buf->st_mode))
        mini_printf("Type: f\n");
    if (S_ISDIR(buf->st_mode))
        mini_printf("Type: d\n");
    if (S_ISCHR(buf->st_mode))
        mini_printf("Type: c\n");
    if (S_ISBLK(buf->st_mode))
        mini_printf("Type: b\n");
    if (S_ISFIFO(buf->st_mode))
        mini_printf("Type: p\n");
    if (S_ISLNK(buf->st_mode))
        mini_printf("Type: l\n");
    if (S_ISSOCK(buf->st_mode))
        mini_printf("Type: s\n");
    return (0);
}

int search_stat(char **av, struct stat *buf)
{
    search_type(buf);
    mini_printf("Inode: %d\n", buf->st_ino);
    mini_printf("Hard link: %d\n", buf->st_nlink);
    mini_printf("Size: %d\n", buf->st_size);
    mini_printf("Allocated space: %d\n", buf->st_blocks);
    mini_printf("Minor: %u\n", minor(buf->st_dev));
    mini_printf("Major: %u\n", major(buf->st_dev));
    mini_printf("UID: %d\n", buf->st_uid);
    mini_printf("GID: %d\n", buf->st_gid);
}

int main(int ac, char **av)
{
    struct stat buf;

    if (stat(av[1], &buf) == -1) {
        write(2, "No such file or directory", 26);
        return (84);
    }
    search_name(av[1]);
    search_stat(av, &buf);
    return (0);
}
