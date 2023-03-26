/*
** EPITECH PROJECT, 2022
** FRAMEBUFFER_H_
** File description:
** FRAMEBUFFER_H_
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef FRAMEBUFFER_H_
    #define FRAMEBUFFER_H_
    struct framebuffer {
        unsigned int width;
        unsigned int height;
        sfUint8 *pixels;
    };
    struct game {
        sfVideoMode mode;
        sfRenderWindow* window;
        sfTexture* texture;
        sfTexture* duck;
        sfSprite* sprite;
        sfSprite* sprite_duck;
        sfEvent event;
        sfIntRect rect;
        sfClock * clock;
        sfTime time;
        sfVector2f pos;
        int score;
        int life;
        float speed;
    };
    struct text {
        sfText * text;
        sfVector2f pos_text;
        sfText * text_score;
        sfVector2f pos_score;
        sfFont * font;
        sfText * gameover;
        sfVector2f pos_gameover;
    };
    typedef struct framebuffer framebuffer_t;
    framebuffer_t *framebuffer_create(unsigned int width, unsigned int height);
    struct game init_val(struct game g);
    struct game perdu(struct game g);
    void my_putchar(char c);
    int my_putstr(char const *str);
    int my_put_nbr(int nb);
    int my_getnbr(char *str);
    char *my_getchar(int i);
    struct text display_text(struct text t);
    void all_draw(struct game g, struct text t);
    void all_destroy(struct game g, struct text t);
    void manage_mouse_click(sfMouseButtonEvent event);
    void analyse_events(sfRenderWindow *window, sfEvent event, int life);
    void move_rect(sfIntRect *rect, int offset, int max_value);
    void end(struct game g, struct text t);
    int my_hunter(struct game g, struct text t);
#endif    /* FRAMEBUFFER_H_ */
