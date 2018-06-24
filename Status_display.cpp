#include "Status_display.h"
#include "global.cpp"

void Status_display::update_int(int dn)
{
    this->num_int += dn;
}

void Status_display::update_float(float dn)
{
    this->num_float += dn;

    if (this->num_float >= MAX_SCORE)
        this->num_float = MAX_SCORE;
}

void Status_display::draw()
{
    // show image
    al_draw_bitmap(this->img, this->img_x, this->img_y, 0);
    // show text
    if (this->num_type == 0) {
        al_draw_textf(this->font, this->txt_color, this->txt_x, this->txt_y,
            0, "%s%d", this->text, this->num_int);
    }
    else if (this->num_type == 1) {
        al_draw_textf(this->font, this->txt_color, this->txt_x, this->txt_y,
            0, "%s%.1f", this->text, this->num_float);
    }
    else if (this->num_type == 2) {
        int minute = this->num_int / 60;
        int second = this->num_int % 60;
        al_draw_textf(this->font, this->txt_color, this->txt_x, this->txt_y,
            0, "%02d:%02d", minute, second);
    }
}
