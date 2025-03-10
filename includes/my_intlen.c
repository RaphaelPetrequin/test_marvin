/*
** EPITECH PROJECT, 2023
** MY_INTLEN
** File description:
** return the len of nb
*/

int my_intlen(int nb)
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
