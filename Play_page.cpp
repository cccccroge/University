#include "Play_page.h"
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
    al_clear_to_color(al_map_rgb(0, 128, 0));

    font = al_load_ttf_font("assets/terminal.ttf", 20, 0);
    this->menu = new Menu(LEVEL_WIDTH, 0);

    al_draw_bitmap(bg_play, 0, 0, 0);
    cout<<"miku\n";
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
            /*
            if(!menu->get_tower_picker()->getTouch()){
                int x = e.mouse.x;
                int y = e.mouse.y;
                int inside_num = this->menu->get_tower_picker()
                    ->is_inside_one(x, y);
                int expanded_num = this->menu->get_tower_picker()
                        ->get_expanded_num();
                //cout<<expanded_num<<" "<<inside_num<<endl;
                if (inside_num != -1) {
                    if (inside_num != expanded_num) {
                        //cout<<"miku\n";
                        this->menu->get_tower_picker()->set_expanded_num(inside_num);
                        menu->get_tower_picker()->touch=true;
                    }
                }/*
                else {
                    if (expanded_num != -1) {
                    //cout<<"02020202002020202222222222\n";
                        system("pause");
                        this->menu->get_tower_picker()->set_expanded_num(-1);
                    }
                }*/
                int x = e.mouse.x;
                int y = e.mouse.y;
                cout<<menu->get_tower_picker()->inside_num<<endl;
                if(menu->get_tower_picker()->inside_num==-1){
                    menu->get_tower_picker()->inside_num=
                    this->menu->get_tower_picker()->is_inside_one(x, y);
                    if(menu->get_tower_picker()->inside_num!=-1)menu->get_tower_picker()->set_button(menu->get_tower_picker()->inside_num);
                }else if(menu->get_tower_picker()->inside_num==0){
                    menu->get_tower_picker()->inside_num=
                    this->menu->get_tower_picker()->is_inside_one(x, y);
                    if(menu->get_tower_picker()->inside_num!=0)menu->get_tower_picker()->set_button(menu->get_tower_picker()->inside_num);
                }else if(menu->get_tower_picker()->inside_num==1){
                    menu->get_tower_picker()->inside_num=
                    this->menu->get_tower_picker()->is_inside_one(x, y);
                    if(menu->get_tower_picker()->inside_num!=1)menu->get_tower_picker()->set_button(menu->get_tower_picker()->inside_num);
                }else if(menu->get_tower_picker()->inside_num==2){
                    menu->get_tower_picker()->inside_num=
                    this->menu->get_tower_picker()->is_inside_one(x, y);
                    if(menu->get_tower_picker()->inside_num!=2)menu->get_tower_picker()->set_button(menu->get_tower_picker()->inside_num);
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
                if(game_update_monster())return false;
                if(monsterSet.size() == 0 && !al_get_timer_started(monster_pro))return false;
                this->menu->draw();
                for(int i=0; i<monsterSet.size(); i++)
                {
                    //cout<<"miku";
                    monsterSet[i]->Draw();
                }
                al_flip_display();//road_grid
            }else if(e.timer.source == monster_pro){
                Monster *m = create_monster();
                if(m != NULL)
                    monsterSet.push_back(m);
            }
        }
    }
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

