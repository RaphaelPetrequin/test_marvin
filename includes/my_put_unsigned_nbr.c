/*
** EPITECH PROJECT, 2023
** MY_PUT_UNSIGNED_NBR
** File description:
** my_put_unsigned_nbr
*/

#include "my.h"

unsigned int my_put_unsigned_nbr(unsigned int nb)
{
    int rest;

    if (nb >= 0) {
        if (nb >= 10) {
            rest = nb % 10;
            nb = nb / 10;
            my_put_nbr(nb);
            my_putchar(48 + rest);
        }
    }
    return (0);
}
