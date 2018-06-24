#ifndef STATUS_DISPLAY_H
#define STATUS_DISPLAY_H

/*==============================*/
// [ description ]
// a display that can show an image and a line of text(show some stats)
// furthermore, it has ability to change the number in that text
// so it can be used to make UI elements
//
// [ constructor parameters ]
// x: image x cord. in pixel
// y: image y cord. in pixel
// txt_offset_x: text x cord. offset from image's x
// txt_offset_y: text y cord. offset from image's y
// img_path: image file path
// pre_txt: texts that you want to show before the number
// font_path: true-font-type font file path
// font_size: font size in pt
// font_color: ALLEGRO_COLOR for font color
// type: 0 means you want a integer displayer,
//       1 means float-point, and 2 means standard time system
//       which draw 2 integers representing minute/second
//
// [ attention ]
// 1.outside objects can change the number of UI via
//   'update_int' or 'update_float'
//
/*==============================*/

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <cstring>

class Status_display
{
public:
    Status_display(int x, int y, int txt_offset_x, int txt_offset_y,
        char *img_path, char *pre_txt, char *font_path, int font_size, ALLEGRO_COLOR color,
        int type, float num):
        img_x(x), img_y(y), txt_x(x + txt_offset_x), txt_y(y + txt_offset_y), num_type(type),
        num_int((int)num), num_float(num), text(pre_txt)
    {
        this->img = al_load_bitmap(img_path);
        this->font = al_load_font(font_path, font_size, 0);
        this->txt_color = color;

        this->draw();
    }
    void update_int(int dn);
    void update_float(float dn);
    int get_num_int() { return this->num_int; }
    int get_num_float() { return this->num_float; }
    void draw();

private:
    int img_x, img_y;
    int txt_x, txt_y;
    ALLEGRO_BITMAP *img;
    ALLEGRO_FONT *font;
    ALLEGRO_COLOR txt_color;
    int num_int;
    float num_float;
    char *text;
    int num_type;
};

#endif // STATUS_DISPLAY_H
