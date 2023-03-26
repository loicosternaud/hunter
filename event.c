/*
** EPITECH PROJECT, 2022
** CSFML
** File description:
** CSFML
*/

#include "framebuffer.h"

void manage_mouse_click(sfMouseButtonEvent event)
{
    my_putstr("Mouse x=");
    my_put_nbr(event.x);
    my_putchar(' ');
    my_putstr("y=");
    my_put_nbr(event.y);
    my_putchar('\n');
}

void analyse_events(sfRenderWindow *window, sfEvent event, int life)
{
    if (event.type == sfEvtClosed ||
    sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue || life <= 0) {
        sfRenderWindow_close(window);
    }
}

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    if (rect->left == max_value - offset) {
        rect->left = 0;
    } else {
        rect->left += offset;
    }
}
