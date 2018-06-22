#define START_PAGE_H
#ifdef START_PAGE_H

#include <allegro5/allegro.h>
#include <string>

class Start_page
{
public:
    Start_page(ALLEGRO_EVENT_QUEUE *q) : running(true), event_queue(q) {}
    void run();
    void next(std::string op);

private:
    bool running;
    ALLEGRO_EVENT_QUEUE *event_queue;
};

#endif // START_PAGE_H
