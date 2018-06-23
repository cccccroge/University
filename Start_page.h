#ifndef START_PAGE_H
#define START_PAGE_H

#include <allegro5/allegro.h>
#include <string>

#include "Button.h"

class Start_page
{
public:
    Start_page(ALLEGRO_EVENT_QUEUE *q, int *t) : event_queue(q),
        next_page_type(t) {}
    void init();
    bool run();

private:
    ALLEGRO_EVENT_QUEUE *event_queue;
    int *next_page_type;
    Button *play_button;
    Button *option_button;
    Button *exit_button;
};

#endif // START_PAGE_H
