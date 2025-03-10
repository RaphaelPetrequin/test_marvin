/*
** EPITECH PROJECT, 2023
** MY_STR_TO_WORD_ARRAY
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>
#include "my.h"

int make_nbwords(const char *str)
{
    int nbwords = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (is_alphanum(str[i]) == 0) {
            nbwords = nbwords + 1;
        }
    }
    return (nbwords);
}

int make_lenword(const char *str, int word)
{
    int lenword = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (is_alphanum(str[i]) == 1 && word == 0)
            lenword++;
        if (is_alphanum(str[i]) != 1)
            word = word - 1;
    }
    return (lenword);
}

char **my_str_to_word_array(const char *str)
{
    int nbwords = make_nbwords(str);
    char **tab = malloc(sizeof(char *) * nbwords + 1);
    int lenword;
    int i;
    int index;

    tab[nbwords] = 0;
    for (int word = 0; word < nbwords; word++) {
        index = 0;
        lenword = make_lenword(str, word);
        tab[word] = malloc(sizeof(char) * (lenword) + 1);
        for (i; str[i] != '\0' && is_alphanum(str[i]) == 1; i++) {
            tab[word][index] = str[i];
            index++;
        }
        tab[word][index] = '\0';
        i++;
    }
    return (tab);
}
