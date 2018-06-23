#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#include "global.cpp"
#include "Page_mannager.h"

int main()
{
    // initialization
    al_init();
    al_install_keyboard();
    al_install_mouse();
    al_init_image_addon();


    // create elements to  structure a game loop
    ALLEGRO_DISPLAY *display = al_create_display(GAME_WIDTH, GAME_HEIGHT);
    ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
    ALLEGRO_TIMER *game_tick_timer = al_create_timer(1.0 / GAME_FPS);

    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_mouse_event_source());
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(game_tick_timer));
    al_start_timer(game_tick_timer);


    // main loop
    Page_mannager *pm = new Page_mannager(event_queue);
    while (1) {
        if (pm->run_page()) {
            std::cout << "end of current page, next is "
                << pm->get_next_page_type() << std::endl;
            continue;
        }
        else {
            std::cout << "terminate main loop." << std::endl;
            break;
        }
    }


    // free memory
    delete pm;
    al_destroy_display(display);
    al_uninstall_keyboard();
    al_uninstall_mouse();
    al_shutdown_image_addon();

    return 0;
}
