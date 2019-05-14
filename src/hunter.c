/*
** EPITECH PROJECT, 2018
** open_window
** File description:
** try to use click
*/

#include "../include/my.h"
#include <time.h>

void draw_sprite(texture_t help);
void destroy(texture_t help);
void reset_duck(sfSprite* duck_sprite, sfVector2f pos);

void move_rect(sfIntRect *rect, texture_t texture, my_timer_t timer)
{
    sfVector2f pos;

    timer.time = sfClock_getElapsedTime(timer.clock);
    timer.seconds = timer.time.microseconds / 1000000.0;
    if (timer.seconds > 0.1) {
        if (rect->left != 330) {
            rect->left = rect->left + 110;
            if (rect->left == 330)
                rect->left = 0;
        }
        sfClock_restart(timer.clock);
    }
    pos = sfSprite_getPosition(texture.duck_sprite);
    if (pos.x > 1280.0) {
        my_putstr("Game over !\n");
        sfRenderWindow_close(texture.window);
    }
}

texture_t sprite(texture_t help, sfIntRect *rect)
{
    sfVideoMode mode = {1280, 769, 32};

    rect->top = 0;
    rect->width = 110;
    rect->height = 110;
    rect->left = 0;
    help.window = sfRenderWindow_create(mode, "Duck Hunt boys", sfResize |
                                        sfClose, NULL);
    help.texture = sfTexture_createFromFile("hunter.jpg", NULL);
    help.duck_texture =
        sfTexture_createFromFile("sprite_duck.png",NULL);
    help.sprite = sfSprite_create();
    help.duck_sprite = sfSprite_create();
    sfSprite_setTexture(help.sprite, help.texture, sfTrue);
    sfSprite_setTexture(help.duck_sprite, help.duck_texture, sfTrue);
    return (help);
}

texture_t text(texture_t help)
{
    help.font = sfFont_createFromFile("arial.ttf");
    help.text = sfText_create();
    sfText_setString(help.text, "Duck Hunt");
    sfText_setFont(help.text, help.font);
    sfText_setCharacterSize(help.text, 25);
    return (help);
}
void windows_events(void)
{
    duck_t duck;
    texture_t texture = sprite(texture, &duck.rect);
    sfEvent event;
    my_timer_t timer;

    texture = text(texture);
    duck.move.x = 0.5;
    timer.clock = sfClock_create();
    while (sfRenderWindow_isOpen(texture.window)) {
        while (sfRenderWindow_pollEvent(texture.window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(texture.window);
            analyse_events(texture.window, event, texture.duck_sprite);
        }
        sfSprite_move(texture.duck_sprite, duck.move);
        draw_sprite(texture);
        move_rect(&duck.rect, texture, timer);
        sfSprite_setTextureRect(texture.duck_sprite, duck.rect);
    }
    destroy(texture);
}

int error(int ac, char **av)
{
    if (ac == 1) {
        windows_events();
        return 0;
    }
    if (ac == 2 && my_strdif(av[1], "-h") == 0) {
        write(1, "Type ./my_hunter and shoot the duck !\n", 38);
        return 0;
    }
    if (ac == 2 && my_strdif(av[1], "-h") == 1) {
        write(2, "Did you meant -h ?\n", 19);
        return 84;
    }
    if (ac > 2) {
        write(2, "Too many arguments !\n", 21);
        return 84;
    }
}
