#ifndef PAGE_MANNAGER_H
#define PAGE_MANNAGER_H

#include <allegro5/allegro.h>
#include "Start_page.h"

enum PAGE_TYPE { START = 1, PLAY, END};

class Page_mannager
{
public:
    Page_mannager(ALLEGRO_EVENT_QUEUE *q): event_queue(q), next_page_type(START)
    {
        this->start_page = new Start_page(q, &next_page_type);
    }
    bool run_page();
    int get_next_page_type() { return this->next_page_type; }

private:
    ALLEGRO_EVENT_QUEUE *event_queue;
    int next_page_type;
    Start_page *start_page;
};

#endif // PAGE_MANNAGER_H
