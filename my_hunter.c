/*
** EPITECH PROJECT, 2022
** CSFML
** File description:
** CSFML
*/

#include "framebuffer.h"

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
    framebuffer_t *framebuffer = malloc(sizeof(framebuffer_t));
    framebuffer->height = height;
    framebuffer->width = width;
    framebuffer->pixels = malloc(width * height * sizeof(sfColor));
    return framebuffer;
}

struct game init_val(struct game g)
{
    g.mode.width = 800; g.mode.height = 600; g.mode.bitsPerPixel = 32;
    g.rect.width = 110; g.rect.height = 110; g.rect.left = 0; g.rect.top = 0;
    g.clock = sfClock_create(); g.pos.y = rand() % 300;
    g.window = sfRenderWindow_create(g.mode, "SFML window",
    sfResize | sfClose, NULL);
    g.texture = sfTexture_createFromFile("forest.jpg", NULL);
    g.duck = sfTexture_createFromFile("spritesheet.png", NULL);
    g.sprite = sfSprite_create(); g.sprite_duck = sfSprite_create();
    sfSprite_setTexture(g.sprite, g.texture, sfTrue);
    sfSprite_setTexture(g.sprite_duck, g.duck, sfTrue);
    sfRenderWindow_setFramerateLimit(g.window, 30);
    return g;
}

struct game perdu(struct game g)
{
    move_rect(&g.rect, 110, 330);
    g.pos.x += 30;
    if (g.pos.x >= 800) {
        g.life--; g.pos.y = rand() % 300; g.pos.x = 0;
    }
    sfSprite_setPosition(g.sprite_duck, g.pos);
    sfClock_restart(g.clock);
    return g;
}

int my_hunter(struct game g, struct text t)
{
    g = init_val(g); t = display_text(t); float sec; g.life = 3; g.score = 0;
    g.speed = 0.15;
    while (sfRenderWindow_isOpen(g.window)) {
        while (sfRenderWindow_pollEvent(g.window, &g.event)) {
            analyse_events(g.window, g.event, g.life);
        }
        switch ((sfMouse_isButtonPressed(sfMouseLeft))) {
            case 1: if (sfMouse_getPosition(sfMouseLeft).x >= g.pos.x &&
                sfMouse_getPosition(sfMouseLeft).x <= (g.pos.x + 110) &&
                sfMouse_getPosition(sfMouseLeft).y >= g.pos.y &&
                sfMouse_getPosition(sfMouseLeft).y <= (g.pos.y + 150)) {
                    g.pos.y = rand() % 300; g.pos.x = 0; g.score += 10;
                    g.speed -= 0.008;
                    sfText_setString(t.text_score, my_getchar(g.score));
                } break;
        } g.time = sfClock_getElapsedTime(g.clock);
        sec = g.time.microseconds / 1000000.0;
        (sec > g.speed) ? (g = perdu(g)) : g; all_draw(g, t);
    }
    all_destroy(g, t); end(g, t); return (0);
}

int main(int ac, char **av)
{
    struct game g;
    struct text t;
    if (ac == 1) {
        my_hunter(g, t);
    } else if (av[1][0] == '-' && av[1][1] == 'h') {
        my_putstr("MY_HUNTER\n");
        my_putchar('\n');
        my_putstr("DESCRIPTION\n");
        my_putstr("My Hunter est un jeu de tir en vue subjective dans lequel ");
        my_putstr("l'objectif est de toucher des cibles mouvantes en visant ");
        my_putstr("et tirant dessus à l'aide du clic gauche");
        my_putchar('\n');
    }
}
