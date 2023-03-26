/*
** EPITECH PROJECT, 2022
** CSFML
** File description:
** CSFML
*/

#include "framebuffer.h"

struct text display_text(struct text t)
{
    t.pos_text.x = 50; t.pos_text.y = 550;
    t.pos_score.x = 180; t.pos_score.y = 550;
    t.font = sfFont_createFromFile("PixeloidSans.ttf");
    t.text = sfText_create();
    t.text_score = sfText_create();
    sfText_setString(t.text, "Score :");
    sfText_setPosition(t.text, t.pos_text);
    sfText_setPosition(t.text_score, t.pos_score);
    sfText_setFont(t.text, t.font);
    sfText_setFont(t.text_score, t.font);
    sfText_setCharacterSize(t.text, 25);
    sfText_setCharacterSize(t.text_score, 25);
    return t;
}

void all_draw(struct game g, struct text t)
{
    sfRenderWindow_clear(g.window, sfBlack);
    sfSprite_setTextureRect(g.sprite_duck, g.rect);
    sfRenderWindow_drawSprite(g.window, g.sprite, NULL);
    sfRenderWindow_drawSprite(g.window, g.sprite_duck, NULL);
    sfRenderWindow_drawText(g.window, t.text, NULL);
    sfRenderWindow_drawText(g.window, t.text_score, NULL);
    sfRenderWindow_display(g.window);
}

void all_destroy(struct game g, struct text t)
{
    sfClock_destroy(g.clock);
    sfSprite_destroy(g.sprite);
    sfSprite_destroy(g.sprite_duck);
    sfTexture_destroy(g.texture);
    sfTexture_destroy(g.duck);
    sfRenderWindow_destroy(g.window);
}

void end(struct game g, struct text t)
{
    my_putstr("Final Score : ");
    my_put_nbr(g.score);
    my_putchar('\n');
}
