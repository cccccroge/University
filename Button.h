#ifndef BUTTON_H
#define BUTTON_H

/*==============================*/
//
// A very basic image-button.
// Provide two image state: default, hover
// it will alter when cursor goes in or out the image rectangle,
// changing to the corresponded image
//
/*==============================*/

#include <allegro5/allegro.h>

class Button
{
public:
    Button(int x, int y, char *path_d, char *path_h): state(0),
        x_pos(x), y_pos(y)
    {
        this->default_image = al_load_bitmap(path_d);
        this->hover_image = al_load_bitmap(path_h);
        al_draw_bitmap(default_image, this->x_pos, this->y_pos, 0);
    }
    void alt_image();

private:
    int state;
    int x_pos, y_pos;
    ALLEGRO_BITMAP *default_image;
    ALLEGRO_BITMAP *hover_image;

    void alt_state();
};

#endif // BUTTON_H
