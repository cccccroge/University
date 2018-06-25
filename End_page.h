#ifndef END_PAGE_H
#define END_PAGE_H

#include <allegro5/allegro.h>
#include <string>

class End_page
{
public:
    End_page(ALLEGRO_EVENT_QUEUE *q, int *t) : event_queue(q),
        next_page_type(t)
    {
        this->bg_win = al_load_bitmap("assets/end_page_win.png");
        this->bg_win = al_load_bitmap("assets/end_page_lose.png");
    }
    void init(int);
    bool run();

private:
    ALLEGRO_EVENT_QUEUE *event_queue;
    ALLEGRO_BITMAP *bg_win;
    ALLEGRO_BITMAP *bg_lose;
    int *next_page_type;
    int type;
};

#endif // END_PAGE_H

