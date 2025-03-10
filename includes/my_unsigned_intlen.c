/*
** EPITECH PROJECT, 2023
** MY_UNSIGNED_INTLEN
** File description:
** returns the len of unsigned int nb
*/

#include "my.h"

int my_unsigned_intlen(unsigned int nb)
{
    int res = 1;

    if (nb < 0) {
        nb = nb * -1;
        res ++;
        for (res; nb != 0; res++) {
            nb = nb / 10;
        }
    } else {
        for (res; nb > 9; res++) {
            nb = nb / 10;
        }
    }
    return (res);
}
