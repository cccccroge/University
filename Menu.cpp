#include "Menu.h"

void Menu::draw()
{
    al_draw_bitmap(this->bar, x, y, 0);
    this->money_display->draw();
    this->score_display->draw();
    this->time_display->draw();
}


