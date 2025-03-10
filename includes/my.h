/*
** EPITECH PROJECT, 2023
** MY
** File description:
** Contains the prototypes of the functions exposed by libmy.a
*/

#include <stdlib.h>
#include <stdarg.h>
#include <dirent.h>
#include <stddef.h>

#ifndef MY
    #define MY

void my_putchar(char);
int my_put_nbr(int);
int my_putstr(char const *);
int my_strlen(char const *);
int find_flag(const char, va_list);
int my_unsigned_intlen(unsigned int nb);
unsigned int my_put_unsigned_nbr(unsigned int nb);
int my_intlen(int nb);
int mini_printf(const char *, ...);
int error_message(char *);
int is_flag(char *);
char *my_strlowcase(char *);
int is_alpha(char);
char *my_strcpy(char *dest, char const *src);
int make_my_ls_l(struct dirent *entries, char *dirpath);
char **get_files_names(struct dirent *entries, char *dirpath);
int make_my_ls_a(struct dirent *entries, char *dirpath);
char **my_str_to_word_array(const char *str);
int is_alphanum(char c);
char **get_in_alpha_order(struct dirent *entries, char *dirpath, char **);
int get_nbname(char **filesname, struct dirent *entries, DIR *mydir);
char **get_rev_alphorder(struct dirent *entries, char *, char **);
int make_my_ls_r(struct dirent *entries, char *dirpath);
int strchcmp(char *s1, char *s2);
int make_my_ls_t(struct dirent *entries, char *dirpath);

#endif /*MY*/
