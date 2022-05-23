/*
** EPITECH PROJECT, 2022
** jam111
** File description:
** main.c
*/

#include "../include/jam.h"
#include "../include/pos.h"
#include "../include/images.h"

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
    int indexx[15] = index_x;
    int indexy[15] = index_y;
    sfTexture *t_tree = sfTexture_createFromFile(tree, NULL);
    sfSprite *s_tree = sfSprite_create();

    sfTexture **t_portraits = malloc(sizeof(sfTexture*) * 16);
    sfSprite **s_portraits = malloc(sizeof(sfSprite*) * 16);

    sfEvent event;
    sfClock *clock;
    sfTime time;
    float seconds;

    sfVector2f pos = {0, 0};

    t_portraits[15] = NULL;
    t_portraits[0] = sfTexture_createFromFile(leo, NULL);
    t_portraits[1] = sfTexture_createFromFile(homer, NULL);
    t_portraits[2] = sfTexture_createFromFile(marge, NULL);

    for (int i = 3; i < 15; i++)
        t_portraits[i] = sfTexture_createFromFile(bart, NULL);

    s_portraits[15] = NULL;

    for (int i = 0; i < 15; i++) {
        s_portraits[i] = sfSprite_create();
        sfSprite_setTexture(s_portraits[i], t_portraits[i], sfTrue);
    }

    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    
    sfSprite_setTexture(s_tree, t_tree, sfTrue);

    

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
        sfRenderWindow_drawSprite(window, s_tree, NULL);
        for (int i = 0; s_portraits[i] != NULL; i++) {
            pos.x = indexx[i];
            pos.y = indexy[i];
            sfSprite_setPosition(s_portraits[i], pos);
            sfRenderWindow_drawSprite(window, s_portraits[i], NULL);
        }
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
    return (0);
}
