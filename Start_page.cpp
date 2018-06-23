#include "Start_page.h"

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


