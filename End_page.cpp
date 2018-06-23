#include "End_page.h"

enum PAGE_TYPE { START = 1, PLAY, END};

bool End_page::run()
{
    while (1) {
        ALLEGRO_EVENT e;
        al_wait_for_event(this->event_queue, &e);

        if (e.type == ALLEGRO_EVENT_KEY_DOWN) {
            if (e.keyboard.keycode == ALLEGRO_KEY_N) {
                return false;
            }
            else if (e.keyboard.keycode == ALLEGRO_KEY_B) {
                *(this->next_page_type) = PLAY;
                return true;
            }
        }
        if (e.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            return false;
        }
    }
}



