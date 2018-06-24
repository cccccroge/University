#ifndef PLAY_PAGE_H
#define PLAY_PAGE_H

#include <allegro5/allegro.h>
#include <string>
#include<vector>
#include "global.cpp"
#include "Menu.h"

class Play_page
{
public:
    Play_page(ALLEGRO_EVENT_QUEUE *q, int *t) : event_queue(q),
    next_page_type(t) {bg_play= al_load_bitmap("assets/grass_background.jpg");}
    void init();
    bool run();
    void print_road();

private:
    ALLEGRO_BITMAP *bg_play ;
    ALLEGRO_EVENT_QUEUE *event_queue;
    ALLEGRO_FONT *font;
    int *next_page_type;
    Menu *menu;
    bool levelMap[NumOfGrid];//NumOfGrid
    std::vector<int> road_grid;
//    bool road[51][];//map:1080x720
            //menu:1280x720
};

#endif // PLAY_PAGE_H

