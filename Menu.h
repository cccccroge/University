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
#include "Tower_picker.h"

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

        char *img_path_arr[6] = {
            "assets/big_tits_girl_icon_small.png",
            "assets/big_tits_girl_icon_big.png",
            "assets/big_cockroach_icon_small.png",
            "assets/big_cockroach_icon_big.png",
            "assets/big_bird_icon_small.png",
            "assets/big_bird_icon_big.png"
        };
        this->tower_picker = new Tower_picker(mx, 250, 3,
            200, 50, 70, 100, img_path_arr);
    }
    Status_display* get_money_display() { return this->money_display; }
    Status_display* get_score_display() { return this->score_display; }
    Status_display* get_time_display() { return this->time_display; }
    Tower_picker* get_tower_picker() { return this->tower_picker; }
    void draw();

private:
    int x, y;
    ALLEGRO_BITMAP *bar;
    Status_display *money_display;
    Status_display *score_display;    // this means hp
    Status_display *time_display;    // time counter
    Tower_picker *tower_picker;
};

#endif // MENU_H


