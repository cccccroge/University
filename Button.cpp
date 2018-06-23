#include "Button.h"

void Button::alt_state()
{
    this->state = (this->state ? 0 : 1);
}

void Button::alt_image()
{
    this->alt_state();

    if (this->state == 0) {
        al_destroy_bitmap(this->default_image);
        al_draw_bitmap(this->hover_image, this->x_pos, this->y_pos, 0);
        //al_set_target_bitmap(this->default_image);
        //al_clear_to_color()
    }
    else if (this->state == 1){
        al_destroy_bitmap(this->hover_image);
        al_draw_bitmap(this->default_image, this->x_pos, this->y_pos, 0);
    }
}
