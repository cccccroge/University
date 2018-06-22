#include "Start_page.h"

void Start_page::run()
{
    while (this->running) {
        ALLEGRO_EVENT e;
        al_wait_for_event(this->event_queue, &e);

        if (   e.type == ALLEGRO_EVENT_KEY_DOWN
            || e.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            this->running = false;
        }
    }
}

void Start_page::next(std::string op)
{
    if (op == "start game") {

    } else if (op == "exit game") {
        return;
    }
}
