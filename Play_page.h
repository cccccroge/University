#ifndef PLAY_PAGE_H
#define PLAY_PAGE_H

#include <allegro5/allegro.h>
#include <string>

class Play_page
{
public:
    Play_page(ALLEGRO_EVENT_QUEUE *q, int *t) : event_queue(q),
        next_page_type(t) {}
    bool run();

private:
    ALLEGRO_EVENT_QUEUE *event_queue;
    int *next_page_type;
};

#endif // PLAY_PAGE_H

