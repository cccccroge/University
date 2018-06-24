#ifndef PLAY_PAGE_H
#define PLAY_PAGE_H

#include <allegro5/allegro.h>
#include <string>
#include<vector>
#include "Monster.h"
#include "global.cpp"
#include "Menu.h"
#include "WolfKnight.h"
#include "CaveMan.h"
#include "Wolf.h"
#include "DemonNijia.h"
#include<stdio.h>
#include<iostream>
#include<stdlib.h>

enum {WOLF = 0, WOLFKNIGHT, DEMONNIJIA, CAVEMAN};
class Play_page
{
public:
    Play_page(ALLEGRO_EVENT_QUEUE *q, int *t) : event_queue(q),
    next_page_type(t) {bg_play= al_load_bitmap("assets/grass_background.jpg");}
    void init();
    bool run();
    void print_road();
    Monster* create_monster();
    std::vector<int> ReturnPath() { return road_grid; }
    bool game_update_monster();
private:
    ALLEGRO_BITMAP *bg_play ;
    ALLEGRO_EVENT_QUEUE *event_queue;
    ALLEGRO_FONT *font;
    int *next_page_type;
    Menu *menu;
    bool levelMap[NumOfGrid];//NumOfGrid
    std::vector<int> road_grid;
    std::vector<Monster*> monsterSet;
    int MonsterNum[Num_MonsterType];
};

#endif // PLAY_PAGE_H

