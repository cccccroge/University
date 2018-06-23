#include "Start_page.h"

enum PAGE_TYPE { START = 1, PLAY, END};

void Start_page::init()
{
    al_clear_to_color(al_map_rgb(255, 255, 255));

    ALLEGRO_BITMAP *bg = al_load_bitmap("assets/start_page.jpg");
    al_draw_bitmap(bg, 0, 0, 0);
    al_flip_display();
}

bool Start_page::run()
{
    while (1) {
        ALLEGRO_EVENT e;
        al_wait_for_event(this->event_queue, &e);

        if (e.type == ALLEGRO_EVENT_KEY_DOWN) {
            if (e.keyboard.keycode == ALLEGRO_KEY_N) {
                *(this->next_page_type) = PLAY;
                return true;
            }
        }
        if (e.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            return false;
        }
    }
}


