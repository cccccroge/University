#include "Start_page.h"
#include "global.cpp"

enum PAGE_TYPE { START = 1, PLAY, END};

void Start_page::init()
{
    al_clear_to_color(al_map_rgb(255, 255, 255));

    ALLEGRO_BITMAP *bg = al_load_bitmap("assets/start_page.jpg");
    al_draw_bitmap(bg, 0, 0, 0);
    al_flip_display();

    this->play_button = new Button(GAME_WIDTH / 2, GAME_HEIGHT * 0.67 - 50,
        "assets/play_button_default.png", "assets/play_button_hover.png");
    this->option_button = new Button(GAME_WIDTH / 2, GAME_HEIGHT * 0.67,
        "assets/option_button_default.png", "assets/option_button_hover.png");
    this->exit_button = new Button(GAME_WIDTH / 2, GAME_HEIGHT * 0.67 + 50,
        "assets/exit_button_default.png", "assets/exit_button_hover.png");
}

bool Start_page::run()
{
    while (1) {
        ALLEGRO_EVENT e;
        al_wait_for_event(this->event_queue, &e);

        if (e.type == ALLEGRO_EVENT_KEY_DOWN) {
            if (e.keyboard.keycode == ALLEGRO_KEY_N) {
                *(this->next_page_type) = PLAY;
                return true;
            }
        }
        else if (e.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            return false;
        }
        else if (e.type == ALLEGRO_EVENT_MOUSE_AXES) {
            // check if cursor is inside or outside any button
            int x = e.mouse.x;
            int y = e.mouse.y;

            if (   this->play_button->is_inside(x, y)
                && this->play_button->get_state() == 0) {
                this->play_button->alt_image();
            }
            else if (  !this->play_button->is_inside(x, y)
                    && this->play_button->get_state() == 1) {
                this->play_button->alt_image();
            }

            if (   this->option_button->is_inside(x, y)
                && this->option_button->get_state() == 0) {
                this->option_button->alt_image();
            }
            else if (  !this->option_button->is_inside(x, y)
                    && this->option_button->get_state() == 1) {
                this->option_button->alt_image();
            }

            if (   this->exit_button->is_inside(x, y)
                && this->exit_button->get_state() == 0) {
                this->exit_button->alt_image();
            }
            else if (  !this->exit_button->is_inside(x, y)
                    && this->exit_button->get_state() == 1) {
                this->exit_button->alt_image();
            }
        }
        else if (e.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
            // check which button pressed
            int x = e.mouse.x;
            int y = e.mouse.y;

            if (this->play_button->is_inside(x, y)) {
                *(this->next_page_type) = PLAY;
                return true;
            }
            else if (this->exit_button->is_inside(x, y)) {
                return false;
            }
        }
        else if (e.type == ALLEGRO_EVENT_TIMER) {
            al_flip_display();
        }
    }
}


