/*
** EPITECH PROJECT, 2023
** ERROR_MESSAGE
** File description:
** Displays an error message for my_ls
*/

#include <unistd.h>
#include "my.h"

int error_message(char *av)
{
    char flag[] = "alRdrt";
    int j = 0;
    int cpt = 0;

    for (int i = 1; av[i] != '\0'; i++) {
        for (j; av[i] != flag[j] && flag[j] != '\0'; j++) {
            cpt++;
        }
        if (cpt == 6) {
            write(2, "ls: invalid option -- '", 23);
            write(2, &av[i], 1);
            write(2, "'\nTry 'ls --help' for more information.\n", 40);
            exit(84);
        }
    }
}
