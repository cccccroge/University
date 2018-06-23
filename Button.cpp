#include "Button.h"

void Button::alt_state()
{
    this->state = (this->state ? 0 : 1);
}

void Button::alt_image()
{
    this->alt_state();
    std::cout << "change image" << std::endl;

    if (this->state == 0) {
        al_draw_bitmap(this->default_image, this->x_pos - x_offset,
            this->y_pos - y_offset, 0);
    }
    else if (this->state == 1){
        al_draw_bitmap(this->hover_image, this->x_pos - x_offset,
            this->y_pos - y_offset, 0);
    }
}

bool Button::is_inside(int mouse_x, int mouse_y)
{
    if (   mouse_x >= this->left && mouse_x <= this->right
        && mouse_y >= this->up && mouse_y <= this->down) {
        return true;
    }
    return false;
}
