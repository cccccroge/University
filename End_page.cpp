#include "End_page.h"

enum PAGE_TYPE { START = 1, PLAY, END_WIN, END_LOSE};

void End_page::init(int _type)
{
    this->type = _type;
}

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
        else if (e.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            return false;
        }
        else if (e.type == ALLEGRO_EVENT_TIMER) {
            if (this->type == 0) {
                al_draw_bitmap(this->bg_win, 0, 0, 0);
                al_flip_display();
            }
            else {
                al_draw_bitmap(this->bg_lose, 0, 0, 0);
                al_flip_display();
            }
        }
    }
}



