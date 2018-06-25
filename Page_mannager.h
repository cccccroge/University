#ifndef PAGE_MANNAGER_H
#define PAGE_MANNAGER_H

#include <allegro5/allegro.h>
#include "Start_page.h"
#include "Play_page.h"
#include "End_page.h"

enum PAGE_TYPE { START = 1, PLAY, END_WIN, END_LOSE};

class Page_mannager
{
public:
    Page_mannager(ALLEGRO_EVENT_QUEUE *q): event_queue(q), next_page_type(START)
    {

        this->start_page = new Start_page(q, &next_page_type);
        this->play_page = new Play_page(q, &next_page_type);
        this->end_page = new End_page(q, &next_page_type);

    }
    bool run_page();
    int get_next_page_type() { return this->next_page_type; }

private:
    ALLEGRO_EVENT_QUEUE *event_queue;
    int next_page_type;
    Start_page *start_page;
    Play_page *play_page;
    End_page *end_page;
};

#endif // PAGE_MANNAGER_H
