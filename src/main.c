/*
** EPITECH PROJECT, 2022
** jam111
** File description:
** main.c
*/

#include "../include/jam.h"

sfRenderWindow *create_window(unsigned int width, unsigned int height)
{
    sfVideoMode video_mode;
    sfRenderWindow *window;

    video_mode.width = width;
    video_mode.height = height;
    video_mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(video_mode, "Game Window", sfFullscreen | sfClose, NULL);
}

int main(int ac, char **av)
{
    sfRenderWindow *window = create_window(1920, 1080);

    sfTexture *t_bg = sfTexture_createFromFile("res/bg.png", NULL);
    sfSprite *s_bg = sfSprite_create();

    sfEvent event;
    sfClock *clock;
    sfTime time;
    float seconds;

    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    
    sfSprite_setTexture(s_bg, t_bg, sfTrue);

    if (!window)
        return EXIT_FAILURE;
    while (sfRenderWindow_isOpen(window)) {

        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
            if (event.type == sfEvtKeyPressed) {
                if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
                    sfRenderWindow_close(window);
            }
        }
        sfRenderWindow_drawSprite(window, s_bg, NULL);
        

        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
    return (0);
}