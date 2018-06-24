#ifndef PLAY_PAGE_H
#define PLAY_PAGE_H

#include <allegro5/allegro.h>
#include <string>
#include <vector>
#include "global.cpp"
#include "Menu.h"
#include <stdio.h>
#include <cmath>
#include <list>
#include "Tower.h"

bool compare_tower_y(Tower *t1, Tower *t2);

class Play_page
{
public:
    Play_page(ALLEGRO_EVENT_QUEUE *q, int *t) : event_queue(q),
    next_page_type(t), tile_grid_x(0), tile_grid_y(0), selected_tower(-1)
    {
        bg_play= al_load_bitmap("assets/grass_background.jpg");

        for (int i = 0; i < 27; i++) {
            for (int j = 0; j < 18; j++) {
                this->towerMap[i][j] = -1;
            }
        }

        this->towers = new std::list<Tower*>();
    }
    void init();
    bool run();
    void print_road();
    void print_construct_hint();
    void print_towers();
    bool is_grid_constructable();

private:
    ALLEGRO_BITMAP *bg_play ;
    ALLEGRO_EVENT_QUEUE *event_queue;
    int *next_page_type;
    Menu *menu;
    bool levelMap[NumOfGrid];//NumOfGrid
    int towerMap[27][18];
    std::vector<int> road_grid;
    int tile_grid_x, tile_grid_y;
    int selected_tower;
    std::list<Tower*> *towers;
//    bool road[51][];//map:1080x720
            //menu:1280x720
};

#endif // PLAY_PAGE_H

