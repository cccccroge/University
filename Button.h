#ifndef BUTTON_H
#define BUTTON_H

/*==============================*/
// [ description ]
// A very basic image-button.
// Provide two image state: default, hover
// it will alter when cursor goes in or out the image rectangle,
// changing to the corresponded image
//
// [ constructor parameters ]
// x: button x cord. in pixel
// y: button y cord. in pixel
// path_d: path for default image
// path_h: path for hover image
//
// [ attention ]
// 1.(x, y) will determine the mid point of the button
// 2.two image should be the same size, otherwise it
//   will not show at correct position
// 3.this class does not provide event handler (I don't know how to do it),
//   outside objects should use 'is_inside' and 'get_state' to decide whether call
//   'alt_image' to manipulate the hover effect
//
/*==============================*/

#include <allegro5/allegro.h>
#include <iostream>

class Button
{
public:
    Button(int x, int y, char *path_d, char *path_h): state(0),
        x_pos(x), y_pos(y)
    {
        this->default_image = al_load_bitmap(path_d);
        this->hover_image = al_load_bitmap(path_h);

        this->x_offset = al_get_bitmap_width(default_image) / 2;
        this->y_offset = al_get_bitmap_height(default_image) / 2;

        this->up = y - this->y_offset;
        this->down = y + this->y_offset;
        this->left = x - this->x_offset;
        this->right = x + this->x_offset;

        al_draw_bitmap(this->default_image,
            this->x_pos - x_offset, this->y_pos - y_offset, 0);
    }
    bool is_inside(int mouse_x, int mouse_y);
    void alt_image();
    int get_state() { return this->state; };

private:
    int state;
    int x_pos, y_pos;
    int x_offset, y_offset;
    int left, right, up, down;
    ALLEGRO_BITMAP *default_image;
    ALLEGRO_BITMAP *hover_image;

    void alt_state();
};

#endif // BUTTON_H
