#ifndef END_PAGE_H
#define END_PAGE_H

#include <allegro5/allegro.h>
#include <string>

class End_page
{
public:
    End_page(ALLEGRO_EVENT_QUEUE *q, int *t) : event_queue(q),
        next_page_type(t) {}
    void init();
    bool run();

private:
    ALLEGRO_EVENT_QUEUE *event_queue;
    int *next_page_type;
};

#endif // END_PAGE_H

