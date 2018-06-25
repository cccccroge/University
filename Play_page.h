#ifndef PLAY_PAGE_H
#define PLAY_PAGE_H

#include <allegro5/allegro.h>
#include <string>
#include <vector>
#include "Monster.h"
#include "global.cpp"
#include "Menu.h"
#include "WolfKnight.h"
#include "CaveMan.h"
#include "Wolf.h"
#include "DemonNijia.h"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <list>
#include "Tower.h"

bool compare_tower_y(Tower *t1, Tower *t2);

enum {WOLF = 0, WOLFKNIGHT, DEMONNIJIA, CAVEMAN};

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
    Monster* create_monster();
    std::vector<int> ReturnPath() { return road_grid; }
    bool game_update_monster();
    void check_monster_tower();
    void check_tower_bullets();
    void check_bullets_monster();

private:
    ALLEGRO_BITMAP *bg_play ;
    ALLEGRO_EVENT_QUEUE *event_queue;
    ALLEGRO_FONT *font;
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
    std::vector<Monster*> monsterSet;
    int MonsterNum[Num_MonsterType];
};

#endif // PLAY_PAGE_H

