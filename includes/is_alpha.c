/*
** EPITECH PROJECT, 2023
** IS_ALPHA
** File description:
** is_alpha
*/

int is_alpha(char c)
{
    if (c >= 'a' && c <= 'z') {
        return (1);
    } else {
        return (0);
    }
}
