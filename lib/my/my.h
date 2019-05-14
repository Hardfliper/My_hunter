/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** remove warnings
*/

#ifndef MY_H
#define MY_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

void my_printf(char *str, ...);
void my_putchar(char c);
void my_swap(char *a, char *b);
int my_isneg(int nb);
int my_strlen(char const *str);
char *my_strcpy(char *dest, char const *src);
char *my_revstr(char *str);
char *my_strcat(char *dest, char const *src);
char *my_strncat( char *dest, char const *str, int nb);
int my_put_nbr(int nb);
int number(char *str);
int my_putstr(char const *str);
int flag_nbr(int nb, int p);
int space_handle(char *str, int *i, va_list va, int *p);
char flag_string(char *str, int p);
int flag_char(int letter, int p);

#endif
