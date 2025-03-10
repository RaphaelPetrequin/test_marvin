/*
** EPITECH PROJECT, 2023
** STRCHCMP
** File description:
** strchcmp
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

void specialchar(char *s1b, char *s2b, int *i, int *j)
{
    if (is_alpha(s1b[*i]) == 0)
        if (s1b[*i + 1] != '\0')
            (*i)++;
    if (is_alpha(s2b[*j]) == 0)
        if (s2b[*j + 1] != '\0')
            (*j)++;
}

int specialcase(char *s1b, char *s2b, int i, int j)
{
    if (*s1b == '.' && my_strlen(s2b) > my_strlen(s1b))
        return (1);
    if (*s2b == '.' && my_strlen(s1b) > my_strlen(s2b))
        return (2);
    if (s1b[i] != '\0' && is_alpha(s1b[i]) == 1 && s1b[i] < s2b[j - 1])
        return (1);
    if (s1b[i] != '\0' && is_alpha(s1b[i]) == 1 && s1b[i] > s2b[j - 1])
        return (2);
    if (s2b[j] != '\0' && is_alpha(s2b[j]) == 1 && s2b[j] < s1b[i - 1])
        return (2);
    if (s2b[j] != '\0' && is_alpha(s2b[j]) == 1 && s2b[j] > s1b[i - 1])
        return (1);
    if (my_strlen(s1b) > my_strlen(s2b) && is_alpha(s1b[i - 1]) == 1)
        return (2);
    if (my_strlen(s1b) > my_strlen(s2b) && is_alpha(s1b[i - 1]) != 1)
        return (1);
    if (my_strlen(s2b) > my_strlen(s1b) && is_alpha(s2b[j - 1]) == 1)
        return (1);
    if (my_strlen(s2b) > my_strlen(s1b) && is_alpha(s2b[j - 1]) != 1)
        return (2);
}

int return_specialcase(char *s1b, char *s2b, int i, int j)
{
    if (specialcase(s1b, s2b, i, j) == 1)
        return (1);
    if (specialcase(s1b, s2b, i, j) == 2)
        return (2);
    return (84);
}

int strchcmp(char *s1, char *s2)
{
    int i = 0;
    int j = 0;
    char *s1b = malloc(sizeof(char) * my_strlen(s1) + 1);
    char *s2b = malloc(sizeof(char) * my_strlen(s2) + 1);

    s1b = my_strlowcase(my_strcpy(s1b, s1));
    s2b = my_strlowcase(my_strcpy(s2b, s2));
    while (s1b[i] != '\0' && s2b[j] != '\0') {
        specialchar(s1b, s2b, &i, &j);
        if (s1b[i] < s2b[j])
            return (1);
        if (s1b[i] > s2b[j])
            return (2);
        i++;
        j++;
    }
    return (return_specialcase(s1b, s2b, i, j));
}
