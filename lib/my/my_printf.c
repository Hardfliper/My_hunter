/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** printf
*/

#include "my.h"

int flag_verify(char *str, int i)
{
    while (str[i] == ' ' || str[i] >= '0' && str[i] <= '9') {
        if (str[i] == ' ' && str[i - 1] <= '9' && str[i - 1] >= '0')
            return (1);
        i = i + 1;
    }
    return (0);
}

char basic_flag(char *str, va_list va, int i, int p)
{
    switch (str[i]) {
    case 's' :
        flag_string(va_arg(va, char*), p);
        i++;
        break;
    case 'd' :
    case 'i' :
        flag_nbr(va_arg(va, int), p);
        i++;
        break;
    case 'c' :
        flag_char(va_arg(va, int), p);
        i++;
        break;
    }
    return (0);
}

int increm_i(char *str,int i)
{
    i++;
    while (str[i] == ' ')
        i = i + 1;
    i = i - 1;
    return (i);
}

void my_printf(char *str, ...)
{
    va_list va;
    int p = 0;

    va_start(va, str);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '%' && flag_verify(str, i + 1) == 0) {
            i = i + 1;
            space_handle(str, &i, va, &p);
            basic_flag(str, va, i, p);
            return;
        } else if (str[i] == '%' && flag_verify(str, i + 1) == 1) {
            my_putchar(str[i]);
            my_putchar(str[i + 1]);
            i = increm_i(str, i);
        } else
            my_putchar(str[i]);
    }
    va_end(va);
    return;
}
