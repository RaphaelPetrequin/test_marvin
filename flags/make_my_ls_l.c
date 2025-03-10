/*
** EPITECH PROJECT, 2023
** MAKE_MY_LS
** File description:
** make_my_ls
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include "../includes/my.h"

static int search_type_permissions(struct stat *buf)
{
    mini_printf((S_ISREG(buf->st_mode)) ? "-" : "");
    mini_printf((S_ISDIR(buf->st_mode)) ? "d" : "");
    mini_printf((S_ISCHR(buf->st_mode)) ? "c" : "");
    mini_printf((S_ISBLK(buf->st_mode)) ? "b" : "");
    mini_printf((S_ISFIFO(buf->st_mode)) ? "p" : "");
    mini_printf((S_ISLNK(buf->st_mode)) ? "l" : "");
    mini_printf((S_ISSOCK(buf->st_mode)) ? "s" : "");
    mini_printf((buf->st_mode & S_IRUSR) ? "r" : "-");
    mini_printf((buf->st_mode & S_IWUSR) ? "w" : "-");
    mini_printf((buf->st_mode & S_IXUSR) ? "x" : "-");
    mini_printf((buf->st_mode & S_IRGRP) ? "r" : "-");
    mini_printf((buf->st_mode & S_IWGRP) ? "w" : "-");
    mini_printf((buf->st_mode & S_IXGRP) ? "x" : "-");
    mini_printf((buf->st_mode & S_IROTH) ? "r" : "-");
    mini_printf((buf->st_mode & S_IWOTH) ? "w" : "-");
    mini_printf((buf->st_mode & S_IXOTH) ? "x" : "-");
    mini_printf(" ");
}

static int search_modif_time(struct stat *buf)
{
    time_t time = buf->st_mtime;
    char *ModifTime = ctime(&time);
    int lenModifTime = my_strlen(ModifTime);
    char **tabwords;

    ModifTime[lenModifTime - 1] = '\0';
    tabwords = my_str_to_word_array(ModifTime);
    mini_printf("%s ", tabwords[1]);
    mini_printf("%s ", tabwords[2]);
    mini_printf("%s:", tabwords[3]);
    mini_printf("%s ", tabwords[4]);
}

int run_l(struct dirent *entries, DIR *dir, struct stat *buf)
{
        search_type_permissions(buf);
        mini_printf("%d ", buf->st_nlink);
        mini_printf("%s ", getpwuid(buf->st_uid)->pw_name);
        mini_printf("%s ", getgrgid(buf->st_gid)->gr_name);
        mini_printf("%d ", buf->st_size);
        search_modif_time(buf);
        mini_printf("%s", entries->d_name);
        mini_printf("\n");
}

void print_total(struct dirent *entries, char *dirpath, struct stat *buf)
{
    int total_blocks = 0;
    int block_size = 0;
    DIR *dir = opendir(dirpath);

    entries = readdir(dir);
    stat(dirpath, buf);
    for (int curr = 0; entries != NULL; curr++) {
        if (entries->d_name[0] != '.')
            total_blocks += buf->st_blocks;
        entries = readdir(dir);
    }
    stat("/", buf);
    block_size = buf->st_blksize;
    mini_printf("total %d\n", (block_size / total_blocks) - 1);
    closedir(dir);
}

int make_my_ls_l(struct dirent *entries, char *dirpath)
{
    DIR *dir = opendir(dirpath);
    char **filesname = get_files_names(entries, dirpath);
    struct stat buf;

    print_total(entries, dirpath, &buf);
    entries = readdir(dir);
    stat(dirpath, &buf);
    while (entries != NULL) {
        if (entries->d_name[0] != '.') {
            lstat(entries->d_name, &buf);
            run_l(entries, dir, &buf);
        }
        entries = readdir(dir);
    }
    closedir(dir);
}
