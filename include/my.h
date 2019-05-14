/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** remove warnings
*/

#ifndef MY_H
#define MY_H

#include <unistd.h>
#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>

int my_strdif(char *str1, char *str2);
void close_window(sfRenderWindow *window);
int my_putstr(char const *str);
void my_putchar(char c);
void my_swap(char *a, char *b);
int my_isneg(int nb);
int my_strlen(char const *str);
int my_getnbr(char const *str);
char *my_strcpy(char *dest, char const *src);
char *my_revstr(char *str);
char *my_strcat(char *dest, char const *src);
char *my_strncat( char *dest, char const *str, int nb);
int my_put_nbr(int nb);
int number(char *str);
void my_printf(char *str, ...);
void manage_mouse_click(sfMouseButtonEvent event, sfSprite* duck_sprite);
void analyse_events(sfRenderWindow *window, sfEvent event,
                    sfSprite* duck_sprite);

typedef struct texture {
    sfRenderWindow* window;
    sfTexture* texture;
    sfSprite* duck_sprite;
    sfSprite* sprite;
    sfTexture* duck_texture;
    sfFont* font;
    sfText* text;
}texture_t;

typedef struct duck_hitbox {
    sfIntRect rect;
    sfVector2f move;
}duck_t;

typedef struct clock_var {
    sfClock *clock;
    sfTime time;
    float seconds;
}my_timer_t;

typedef struct pos {
    int x;
    int y;
}pos_sprit_t;

#endif
