/*
** EPITECH PROJECT, 2018
** hunter_duck
** File description:
** animation duck
*/

#include "../include/my.h"
#include <time.h>

void draw_sprite(texture_t help)
{
    sfRenderWindow_drawSprite(help.window, help.sprite, NULL);
    sfRenderWindow_drawSprite(help.window, help.duck_sprite, NULL);
    sfRenderWindow_drawText(help.window, help.text, NULL);
    sfRenderWindow_display(help.window);
}

void destroy(texture_t help)
{
    sfTexture_destroy(help.texture);
    sfTexture_destroy(help.duck_texture);
    sfFont_destroy(help.font);
    sfText_destroy(help.text);
    sfRenderWindow_destroy(help.window);
}

void reset_duck(sfSprite* duck_sprite, sfVector2f pos)
{
    time_t t;

    pos.x = 0;
    srand((unsigned) time(&t));
    pos.y = rand() % 660;
    sfSprite_setPosition(duck_sprite, pos);
}

void manage_mouse_click(sfMouseButtonEvent event, sfSprite* duck_sprite)
{
    texture_t help;
    sfFloatRect hitbox = sfSprite_getGlobalBounds(duck_sprite);
    float left_x = hitbox.left - hitbox.width;
    float right_x = hitbox.left + hitbox.width;
    float top_y = hitbox.top;
    float bot_y = hitbox.top + hitbox.height;
    unsigned int y = 769;
    sfVector2f pos;

    if (event.x >= left_x && event.x <= right_x
        && event.y >= top_y && event.y <= bot_y) {
        reset_duck(duck_sprite, pos);
    }
}

void analyse_events(sfRenderWindow *window,
                    sfEvent event, sfSprite* duck_sprite)
{
    if (event.type == sfEvtMouseButtonPressed) {
        manage_mouse_click(event.mouseButton, duck_sprite);
    }
}

