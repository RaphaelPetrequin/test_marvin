/*
** EPITECH PROJECT, 2023
** MY_STRLOWCASE
** File description:
** Puts every letter of every word in lowercase
*/

#include "my.h"

char *lowercase(char *strbis, int k)
{
    char alpha[] = "abcdefghijklmnopqrstuvwxyz";
    char alphaUp[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (int l = 0; strbis[l] != '\0'; l++) {
        if (strbis[l] == alphaUp[k]) {
            strbis[l] = alpha[k];
        }
    }
    return (strbis);
}

char *my_strlowcase(char *str)
{
    char *strbis = str;

    for (int k = 0; k < 26; k++) {
        lowercase(strbis, k);
    }
    return (strbis);
}
