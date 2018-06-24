#include <iostream>
#include <allegro5/allegro.h>
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>              //Our primitive header file
#include <allegro5/allegro_native_dialog.h>
#include <sstream>
#include <allegro5/allegro_image.h>

#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>


#include "global.cpp"
#include "Page_mannager.h"

ALLEGRO_TIMER *game_tick_timer;
ALLEGRO_TIMER *count_second_timer;

int main()
{
    // initialization
    al_init();
    al_install_keyboard();
    al_install_mouse();
    al_init_image_addon();
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_primitives_addon();

    // create elements to  structure a game loop
    ALLEGRO_DISPLAY *display = al_create_display(GAME_WIDTH, GAME_HEIGHT);
    ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
    game_tick_timer = al_create_timer(1.0 / GAME_FPS);
    count_second_timer = al_create_timer(1.0);

    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_mouse_event_source());
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(game_tick_timer));
    al_register_event_source(event_queue, al_get_timer_event_source(count_second_timer));
    al_start_timer(game_tick_timer);
    al_start_timer(count_second_timer);


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
    al_uninstall_keyboard();
    al_uninstall_mouse();
    al_shutdown_image_addon();
    al_shutdown_font_addon();
    al_shutdown_primitives_addon();
    //al_shutdown_ttf_addon();  // no need to call this by user
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);
    al_destroy_timer(game_tick_timer);
    al_destroy_timer(count_second_timer);
    //al_destroy_bitmap(bg);
    //al_destroy_bitmap(bg_play);


    return 0;
}
