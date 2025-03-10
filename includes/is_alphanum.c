/*
** EPITECH PROJECT, 2023
** IS_ALPHANUM
** File description:
** is_alphanum
*/

int is_alphanum(char c)
{
    if (c >= 'a' && c <= 'z' || (c >= 'A' && c <= 'Z'))
        return (1);
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}
