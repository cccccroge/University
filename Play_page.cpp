#include "Play_page.h"
#include "global.cpp"
#include<iostream>
#include<stdlib.h>
#include <allegro5/allegro_primitives.h>
using namespace std;
enum PAGE_TYPE { START = 1, PLAY, END};
extern ALLEGRO_TIMER *count_second_timer;
extern ALLEGRO_TIMER *game_tick_timer;
//static int _time=0;
void Play_page::init()
{
    al_clear_to_color(al_map_rgb(0, 128, 0));

    font = al_load_ttf_font("assets/terminal.ttf", 20, 0);
    this->menu = new Menu(LEVEL_WIDTH, 0);

    al_draw_bitmap(bg_play, 0, 0, 0);
    cout<<"miku\n";
    al_flip_display();
}

void Play_page::print_road(){
    char buffer1[5], buffer2[5];
    FILE *file;

    //sprintf(buffer1, "road.txt", level);
    file = fopen("road.txt", "r");

    this->road_grid.clear();

    for(int i = 0; i < NumOfGrid; i++)
    {
        this->levelMap[i]= false;
    }
/*
    fscanf(file, "%s", buffer);
    Monster_MAX = atoi(buffer);

    for(int i=0; i < Num_MonsterType; i++)
    {
        fscanf(file, "%s", buffer);
        MonsterNum[i] = atoi(buffer);
        printf("level:%d %d\n", level, atoi(buffer));
    }
*/
    while(fscanf(file, "%s", buffer1) != EOF&&fscanf(file, "%s", buffer2) != EOF) {
        this->levelMap[atoi(buffer1)+atoi(buffer2)*27] = true;
        //road_grid.push_back(atoi(buffer));
    }

    fclose(file);

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
            else if (e.keyboard.keycode == ALLEGRO_KEY_PAD_0) {
                this->menu->get_tower_picker()->set_expanded_num(-1);
            }
            else if (e.keyboard.keycode == ALLEGRO_KEY_PAD_1) {
                this->menu->get_tower_picker()->set_expanded_num(0);
            }
            else if (e.keyboard.keycode == ALLEGRO_KEY_PAD_2) {
                this->menu->get_tower_picker()->set_expanded_num(1);
            }
            else if (e.keyboard.keycode == ALLEGRO_KEY_PAD_3) {
                this->menu->get_tower_picker()->set_expanded_num(2);
            }
        }
        else if (e.type == ALLEGRO_EVENT_MOUSE_AXES) {
            // check if cursor is inside or outside any tower_picker buttons
            int x = e.mouse.x;
            int y = e.mouse.y;
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
                //_time++;
                //cout<<_time<<endl;
                print_road();
                this->menu->draw();
                al_flip_display();
            }
        }
    }
}



