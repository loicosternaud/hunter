/*
** EPITECH PROJECT, 2022
** my_put
** File description:
** my_put
*/

#include "framebuffer.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int i;
    i = 0;
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return (i);
}

int my_put_nbr(int nb)
{
    int div;
    int cp_char = 0;

    div = 1;
    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
        cp_char++;
    }

    while (nb / div > 9)
        div = div * 10;
    while (div >= 1) {
        my_putchar((nb / div) % 10 + 48);
        cp_char++;
        div = div / 10;
    }
    return (cp_char);
}

int my_getnbr(char *str)
{
    int nb = 0;
    int i = 0;
    while (str[i] >= 48 && str[i] <= 57) {
        nb = nb + str[i] - 48;
        nb = nb * 10;
        i++;
    }
    nb /= 10;
    return (nb);
}

char *my_getchar(int i)
{
    int len = 0;
    int k = i;
    if (i == 0)
        return ("0");
    while (k != 0) {
        k = k / 10;
        len++;
    }
    char *c = malloc(sizeof(char) * (len + 1));
    c[len] = '\0';
    len--;
    while (len >= 0) {
        c[len] = i % 10 + 48;
        i = i / 10;
        len--;
    }
    return (c);
}
