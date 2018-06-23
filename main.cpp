#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#include "Page_mannager.h"

#define GAME_WIDTH 1280
#define GAME_HEIGHT 720
#define GAME_FPS 60

int main()
{
    // initialization
    al_init();
    al_install_keyboard();
    al_init_image_addon();


    // create elements to  structure a game loop
    ALLEGRO_DISPLAY *display = al_create_display(GAME_WIDTH, GAME_HEIGHT);
    ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
    ALLEGRO_TIMER *game_tick_timer = al_create_timer(1.0 / GAME_FPS);

    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_start_timer(game_tick_timer);


    // main loop
    Page_mannager *pm = new Page_mannager(event_queue);
    while (1) {
        if (pm->run_page())
            continue;
        else
            break;
    }


    // free memory
    delete pm;
    al_destroy_display(display);
    al_uninstall_keyboard();
    al_shutdown_image_addon();

    return 0;
}
