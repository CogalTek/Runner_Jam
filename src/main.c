/*
** EPITECH PROJECT, 2022
** main
** File description:
** desc
*/

#include <unistd.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#define EXIT_FAILURE 1
#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow* window;
    sfEvent event;

	sfTexture *texture = sfTexture_createFromFile("./src/content/300*100.png", NULL);
    sfSprite *PLAYER = sfSprite_create();
    sfSprite_setTexture(PLAYER, texture, sfTrue);

    /* Create the main window */
    window = sfRenderWindow_create(mode, "SFML window", sfResize | sfClose, NULL);
    if (!window)
        return EXIT_FAILURE;
    /* Start the game loop */
    while (sfRenderWindow_isOpen(window))
    {
        /* Process events */
        while (sfRenderWindow_pollEvent(window, &event))
        {
            /* Close window : exit */
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
            }
            /* Clear the screen */
            sfRenderWindow_clear(window, sfWhite);

            sfRenderWindow_drawSprite(window, PLAYER, NULL);
            /* Update the window */
            sfRenderWindow_display(window);
        }
    /* Cleanup resources */
    sfRenderWindow_destroy(window);
 return 0;
}