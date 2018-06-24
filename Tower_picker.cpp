#include "Tower_picker.h"

int Tower_picker::is_inside_one(int mouse_x, int mouse_y)
{
    int left = this->x;
    int right = this->x + this->w;

    if (mouse_x >= left && mouse_y <= right) {
        int up = this->y;
        for (int i = 0; i < this->capacity; i++) {
            if (mouse_y >= up && mouse_y <= up + this->h) {
                return i;
            }
            up += this->h;
        }
    }
}

void Tower_picker::draw()
{
    int x_normal = this->x;
    int x_expanded = this->x - this->w_expand;
    int y_cur = this->y;    // start drawing point-y

    for (int i = 0; i < this->capacity; i++) {
        // draw expanded image
        if (i == this->expanded_num) {
            al_draw_bitmap(this->buttons->at(2 * i + 1), x_expanded, y_cur, 0);
            y_cur += (this->h + this->h_expand);
        }
        // draw normal image
        else {
            al_draw_bitmap(this->buttons->at(2 * i), x_normal, y_cur, 0);
            y_cur += (this->h);
        }
    }
}
