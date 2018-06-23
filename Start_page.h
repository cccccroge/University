#ifndef START_PAGE_H
#define START_PAGE_H

#include <allegro5/allegro.h>
#include <string>

#include "Page_mannager.h"

class Start_page
{
public:
    Start_page(ALLEGRO_EVENT_QUEUE *q, int *t) : event_queue(q),
        next_page_type(t) {}
    bool run();

private:
    ALLEGRO_EVENT_QUEUE *event_queue;
    int *next_page_type;
};

#endif // START_PAGE_H
