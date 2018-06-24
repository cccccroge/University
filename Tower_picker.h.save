#ifndef TOWER_PICKER_H
#define TOWER_PICKER_H

/*==============================*/
// [ description ]
//
//
// [ constructor parameters ]
//
//
// [ attention ]
//
//
/*==============================*/

#include <allegro5/allegro.h>
#include "Button.h"
#include <vector>

class Rectangle_boundary
{
public:
    Rectangle_boundary(int l, int r, int u, int d):
        left(l), right(r), up(u), down(d) {}

private:
    int left;
    int right;
    int up;
    int down;
};

class Tower_picker
{
public:
    Tower_picker(int x_pos, int y_pos, int num,
        int width, int height, int dx, int dy, char **img_path_array):
        x(x_pos), y(y_pos), capacity(num), w(width), h(height),
        w_expand(dx), h_expand(dy), expanded_num(-1)
    {
        // create the vector to store BITMAP
        this->buttons = new std::vector<ALLEGRO_BITMAP*>();
        this->buttons->resize(2 * (this->capacity));

        int i = 0;
        for (std::vector<ALLEGRO_BITMAP*>::iterator b = this->buttons->begin();
             b != this->buttons->end(); b++) {
            (*b) = al_load_bitmap(img_path_array[i++]);
        }

        // set initial boundary (each is not expanded)
        this->buttons_boundary = new std::vector<Rectangle_boundary*>();
        this->buttons_boundary->resize(this->capacity);

        int y_tmp = this->y;
        for (std::vector<Rectangle_boundary*>::iterator b =
             this->buttons_boundary->begin();
             b != this->buttons_boundary->end(); b++) {
            (*b) = new Rectangle_boundary(this->x, this->x + this->w,
                y_tmp, y_tmp + this->h);
            y_tmp += this->h;
        }
        button[0][0]=x;
        button[0][1]=y;
        button_origin[0][0]=x;
        button_origin[0][1]=y;
        for(int i=1;i<3;i++){
            button[i][0]=x+w*i;
            button_origin[i][0]=x+w*i;
            button[i][1]=y+h*i;
            button_origin[i][1]=y+h*i;
        }
    }
    int is_inside_one(int mouse_x, int mouse_y);
    void set_expanded_num(int n) { this->expanded_num = n; }
    int get_expanded_num() { return this->expanded_num; }
    bool getTouch(){return touch;}
    void draw();
    int inside_num=-1;
    void set_button(int inside_num);

private:
    int x, y;
    int capacity;
    int w, h;
    int w_expand, h_expand;
    bool touch=false;
    std::vector<ALLEGRO_BITMAP*> *buttons;
    std::vector<Rectangle_boundary*> *buttons_boundary;
    int expanded_num;
    int button[3][2];
    int button_origin[3][2];
};


#endif // TOWER_PICKER_H
