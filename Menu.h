#ifndef MENU_H
#define MENU_H

/*==============================*/
// [ description ]
// a side menu for displaying the game status, including
// money, score(hp), and time left at current level
//
// [ constructor parameters ]
// mx: menu x cord. in pixel
// my: menu y cord/ in pixel
//
// [ attention ]
// 1.calling 'draw' will iteratively invoke draw functions of its members,
//   so you don't need to call them independently
//
/*==============================*/

#include <allegro5/allegro.h>
#include "Status_display.h"

class Menu
{
public:
    Menu(int mx, int my): x(mx), y(my)
    {
        this->bar = al_load_bitmap("assets/side_bar.png");

        this->money_display = new Status_display(x + 30, y + 50, 60, 0,
            "assets/money_icon.png", "x ", "assets/KOMIKAX.ttf",
            24, al_map_rgb(215, 215, 215), 0, 200);
        this->score_display = new Status_display(x + 20, y + 130, 70, 10,
            "assets/score_icon.png", "= ", "assets/KOMIKAX.ttf",
            24, al_map_rgb(215, 215, 215), 1, 100.0);
        this->time_display = new Status_display(x + 60, y + 600, 5, -40,
            "assets/time_icon.png", ":", "assets/KOMIKAX.ttf",
            24, al_map_rgb(215, 215, 215), 2, 0);
    }
    Status_display* get_money_display() { return this->money_display; }
    Status_display* get_score_display() { return this->score_display; }
    Status_display* get_time_display() { return this->time_display; }
    void draw();

private:
    int x, y;
    ALLEGRO_BITMAP *bar;
    Status_display *money_display;
    Status_display *score_display;    // this means hp
    Status_display *time_display;    // time counter
};

#endif // MENU_H


