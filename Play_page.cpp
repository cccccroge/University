#include "Play_page.h"
#include "global.cpp"

enum PAGE_TYPE { START = 1, PLAY, END};
extern ALLEGRO_TIMER *count_second_timer;
extern ALLEGRO_TIMER *game_tick_timer;

void Play_page::init()
{
    al_clear_to_color(al_map_rgb(0, 255, 0));

    this->menu = new Menu(LEVEL_WIDTH, 0);

    al_flip_display();
}

bool Play_page::run()
{
    while (1) {
        ALLEGRO_EVENT e;
        al_wait_for_event(this->event_queue, &e);

        if (e.type == ALLEGRO_EVENT_KEY_DOWN) {
            if (e.keyboard.keycode == ALLEGRO_KEY_N) {
                *(this->next_page_type) = END;
                return true;
            }
            else if (e.keyboard.keycode == ALLEGRO_KEY_B) {
                *(this->next_page_type) = START;
                return true;
            }
            else if (e.keyboard.keycode == ALLEGRO_KEY_PAD_PLUS) {
                this->menu->get_money_display()->update_int(50);
                this->menu->get_score_display()->update_float(5.27);
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
                this->menu->draw();
                al_flip_display();
            }
        }
    }
}



