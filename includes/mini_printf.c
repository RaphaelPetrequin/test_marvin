/*
** EPITECH PROJECT, 2023
** MINI_PRINTF
** File description:
** a 1st step to achieve my_printf
*/

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "my.h"

int my_strint(int nb)
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

static int printfu(va_list list)
{
    int nb = va_arg(list, int);
    int count = 0;
    unsigned int res;

    if (nb < 0) {
        res = 4294967296 + nb;
        count = my_unsigned_intlen(nb);
        my_put_unsigned_nbr(res);
    } else {
        count = my_intlen(nb);
        my_put_nbr(nb);
    }
    return (count);
}

static int printfdi(va_list list)
{
    int nb = va_arg(list, int);
    int count = 0;

    my_put_nbr(nb);
    count = my_strint(nb);
    return (count);
}

static int printfs(va_list list)
{
    char *str = va_arg(list, char *);
    int count;

    my_putstr(str);
    return (my_strlen(str));
}

static int printfc(va_list list)
{
    int c = va_arg(list, int);
    int count = 0;

    my_putchar(c);
    count++;
    return (count);
}

static int printfm(va_list list)
{
    int count = 0;

    my_putchar('%');
    count++;
    return (count);
}

int find_flag(const char format, va_list list)
{
    char *flag = malloc(sizeof(char) * 6 + 1);
    int (*tab[7])(va_list) = {&printfm, &printfc,
    &printfs, &printfdi, &printfdi, &printfu};
    int j;

    flag = "%csdiu";
    for (j = 0; format != flag[j]; j++) {
    }
    return (tab[j](list));
}

int mini_printf(const char *format, ...)
{
    va_list list;
    int count = 0;

    va_start(list, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            count = count + find_flag(format[i + 1], list);
            i++;
        } else {
            my_putchar(format[i]);
            count++;
        }
    }
    free;
    va_end(list);
    return (count);
}
