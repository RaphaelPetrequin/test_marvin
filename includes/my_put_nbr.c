/*
** EPITECH PROJECT, 2023
** MY_PUT_NBR
** File description:
** Displays the nb given
*/

#include <unistd.h>
#include "my.h"

int my_put_nbr(int nb)
{
    int rest;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb >= 0) {
        if (nb >= 10) {
            rest = nb % 10;
            nb = nb / 10;
            my_put_nbr(nb);
            my_putchar(48 + rest);
        } else {
            my_putchar(48 + nb % 10);
        }
    }
    return (0);
}
