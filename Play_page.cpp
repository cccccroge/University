#include "Play_page.h"
#include "global.cpp"
#include <iostream>
#include <stdlib.h>
#include "Monster.cpp"
#include <allegro5/allegro_primitives.h>

using namespace std;

enum PAGE_TYPE { START = 1, PLAY, END};
extern ALLEGRO_TIMER *count_second_timer;
extern ALLEGRO_TIMER *game_tick_timer;
extern ALLEGRO_TIMER *monster_pro;
//static int _time=0;
void Play_page::init()
{
    al_draw_bitmap(bg_play, 0, 0, 0);
    font = al_load_ttf_font("assets/terminal.ttf", 20, 0);
    this->menu = new Menu(LEVEL_WIDTH, 0);

    al_flip_display();

    char buffer1[20], buffer2[20];
    FILE *file, *file2;

    //sprintf(buffer1, "road.txt", level);
    file = fopen("road.txt", "r");
    file2=fopen("monster.txt", "r");
    this->road_grid.clear();

    for(int i = 0; i < NumOfGrid; i++)
    {
        this->levelMap[i]= false;
    }


    for(int i=0; i < Num_MonsterType; i++)
    {
        fscanf(file2, "%s", buffer1);
        MonsterNum[i] = atoi(buffer1);
        printf("level:%d %d\n", 1, atoi(buffer1));
    }

    while(fscanf(file, "%s", buffer1) != EOF&&fscanf(file, "%s", buffer2) != EOF) {
        this->levelMap[atoi(buffer1)+atoi(buffer2)*27] = true;
        road_grid.push_back(atoi(buffer1)+atoi(buffer2)*27);
    }

    fclose(file);
    fclose(file2);
}

bool compare_tower_y(Tower *t1, Tower *t2)
{
    return (t1->get_loc_y() < t2->get_loc_y());
}

Monster*
Play_page::create_monster()
{
    Monster *m = NULL;

    if(MonsterNum[WOLF])
    {
        MonsterNum[WOLF]--;
        m = new Wolf(ReturnPath());
    }
    else if(MonsterNum[WOLFKNIGHT])
    {
        MonsterNum[WOLFKNIGHT]--;
        m = new WolfKnight(ReturnPath());
    }
    else if(MonsterNum[DEMONNIJIA])
    {
        MonsterNum[DEMONNIJIA]--;
        m = new DemonNijia(ReturnPath());
    }
    else if(MonsterNum[CAVEMAN])
    {
        MonsterNum[CAVEMAN]--;
        m = new CaveMan(ReturnPath());
    }
    else
    {
        al_stop_timer(monster_pro);
    }

    return m;
}

void Play_page::print_road(){

    for(int i = 0; i < LEVEL_WIDTH/40; i++)//LEVEL_WIDTH =1080,  i=27
    {
        for(int j = 0; j < LEVEL_HEIGHT/40; j++)//LEVEL_HEIGHT = 720, j=18, i*j=486
        {
            char buffer[50];
            sprintf(buffer, "%d", i + j*27);
            if(levelMap[i+j*27]) {
                //cout<<i<<" "<<j<<endl;
                al_draw_filled_rectangle(i*40, j*40, i*40+40, j*40+40, al_map_rgb(255, 244, 173));
                //al_draw_filled_rectangle(0, 0, 40, 40, al_map_rgb(255, 244, 173));

            }
            // For debug usage, if you want to create a new map, you may turn off this comment.
             al_draw_text(font, al_map_rgb(0, 0, 0), i*40 + 20, j*40 + 14, ALLEGRO_ALIGN_CENTER, buffer);
        }
    }
   //system("pause");
}

void Play_page::print_construct_hint()
{
    ALLEGRO_COLOR color;
    if (this->is_grid_constructable())
        color = al_map_rgb(20, 200, 20);
    else
        color = al_map_rgb(200, 20, 20);

    al_draw_rectangle(this->tile_grid_x * 40, this->tile_grid_y * 40,
        this->tile_grid_x * 40 + 40, this->tile_grid_y * 40 + 40,
        color, 2);
}

void Play_page::print_towers()
{
    for (std::list<Tower*>::iterator t = this->towers->begin();
         t != this->towers->end(); t++) {
        (*t)->draw();
    }
}

bool Play_page::run()
{
    while (1) {
        ALLEGRO_EVENT e;
        al_wait_for_event(this->event_queue, &e);

        if (e.type == ALLEGRO_EVENT_KEY_DOWN) {
            //cout<<e.keyboard.keycode <<endl;
            if (e.keyboard.keycode == ALLEGRO_KEY_N) {
                *(this->next_page_type) = END;
                return true;
            }
            else if (e.keyboard.keycode == ALLEGRO_KEY_B) {
                *(this->next_page_type) = START;
                return true;
            }
            else if (e.keyboard.keycode == ALLEGRO_KEY_PAD_PLUS||e.keyboard.keycode == 136) {
                this->menu->get_money_display()->update_int(50);
                this->menu->get_score_display()->update_float(5.27);
            }
        }
        else if (e.type == ALLEGRO_EVENT_MOUSE_AXES) {
            int x = e.mouse.x;
            int y = e.mouse.y;

            // check if cursor is inside or outside any tower_picker buttons
            int inside_num = this->menu->get_tower_picker()
                ->is_inside_one(x, y);
            int expanded_num = this->menu->get_tower_picker()
                    ->get_expanded_num();

            if (inside_num != -1) {
                if (inside_num != expanded_num) {
                    this->menu->get_tower_picker()->set_expanded_num(inside_num);
                }
            }
            else {
                if (expanded_num != -1) {
                    this->menu->get_tower_picker()->set_expanded_num(-1);
                }
            }

            // update tile grid
            if (x <= LEVEL_WIDTH) {
                this->tile_grid_x = floor(x / 40);
                this->tile_grid_y = floor(y / 40);
            }
        }
        else if (e.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
            int x = e.mouse.x;
            int y = e.mouse.y;

            // change selected tower: select another or cancel selecting
            int inside_num = this->menu->get_tower_picker()
                ->is_inside_one(x, y);
            if (inside_num != -1) {
                if (inside_num != this->selected_tower) {
                    int money = this->menu->get_money_display()->
                        get_num_int();
                    int cost;
                    switch (inside_num) {
                    case 0:
                        cost = TOWER_0_COST_LEVEL1;
                        break;
                    case 1:
                        cost = TOWER_1_COST_LEVEL1;
                        break;
                    case 2:
                        cost = TOWER_2_COST_LEVEL1;
                        break;
                    }

                    if (money >= cost) {
                        this->selected_tower = inside_num;
                    }
                    else {
                        // cannot select, no money

                    }
                }
                else {
                    this->selected_tower = -1;
                }
            }

            // create tower if constructible + tower selected
            bool ok = this->is_grid_constructable();
            int selected = this->selected_tower;
            if (ok && selected != -1) {
                Tower *t = new Tower(this->tile_grid_x, this->tile_grid_y,
                    -48, -139, 93, 161, 0, -106,
                    "assets/big_tits_girl_tower.png", "assets/heart.png",
                    100, 3, 30, 18, 30, TOWER_0_COST_LEVEL1);
                this->towers->push_back(t);
                this->towers->sort(compare_tower_y);
            }
        }
        else if (e.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            return false;
        }
        else if (e.type == ALLEGRO_EVENT_TIMER) {
            if (e.timer.source == count_second_timer) {
                this->menu->get_time_display()->update_int(1);
            }
            else if (e.timer.source == game_tick_timer) {
                // redraw every things
                al_draw_bitmap(bg_play, 0, 0, 0);
                print_road();
                for(int i=0; i<monsterSet.size(); i++)
                {
                    //cout<<"miku";
                    monsterSet[i]->Draw();
                }
                this->print_towers();
                if (this->selected_tower != -1) {
                    this->print_construct_hint();
                }
                this->menu->draw();

                al_flip_display();//road_grid

                // check win or lose
                if(game_update_monster())return false;
                if(monsterSet.size() == 0 && !al_get_timer_started(monster_pro))return false;
            }
            else if(e.timer.source == monster_pro){
                Monster *m = create_monster();
                if(m != NULL)
                    monsterSet.push_back(m);
            }
        }
    }
}

bool Play_page::is_grid_constructable()
{
    bool ret = true;

    // can't construct on road
    if (this->levelMap[this->tile_grid_x + this->tile_grid_y * 27]) {
        ret = false;
    }
    // can't construct on the tile which has been constructed
    else if (this->towerMap[this->tile_grid_x][this->tile_grid_y] != -1) {
        ret = false;
    }

    return ret;
}

bool Play_page::game_update_monster(){
    // update every monster
    // check if it is destroyed or reaches end point
    for(int i=0; i < monsterSet.size(); i++)
    {

        bool isDestroyed = false, isReachEnd = false;
        /*
        for(it = towerSet.begin();it != towerSet.end();it++){
            if((*it)->TriggerAttack(monsterSet[i])){
                isDestroyed = true;
            }
        }
        /*TODO:*/
        /*1. For each tower, traverse its attack set*/
        /*2. If the monster collide with any attack, reduce the HP of the monster*/
        /*3. Remember to set isDestroyed to "true" if monster is killed*/
        /*Hint: Tower::TriggerAttack/*/

        isReachEnd = monsterSet[i]->Move();
        /*
        if(isDestroyed)
        {
            Monster *m = monsterSet[i];

            menu->Change_Coin(m->getWorth());
            menu->Gain_Score(m->getScore());
            monsterSet.erase(monsterSet.begin() + i);
            i--;
            delete m;

        }
        else */if(isReachEnd)
        {
            Monster *m = monsterSet[i];

            if(menu->get_score_display()->update_int(m->getDamage()))
                return true;

            monsterSet.erase(monsterSet.begin() + i);
            i--;
            delete m;
        }
    }
    return false;
}

