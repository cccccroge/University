#include "Tower_picker.h"

int Tower_picker::is_inside_one(int mouse_x, int mouse_y)
{
    int left = this->x;
    int right = this->x + this->w;
    if(inside_num==-1){
       if (mouse_x >= left && mouse_y <= right) {
            int up = this->y;
            for (int i = 0; i < this->capacity; i++) {
                if (mouse_y >= up && mouse_y <= up + this->h) {
                    return i;
                }
                up += this->h;
            }
        }return -1;
    }else{
        if(mouse_x>=button[inside_num][0]&&mouse_y>=button[inside_num][1]&&
           mouse_y<=button[inside_num][1]+h+h_expand){
           return inside_num;
        }else if(0){

        }
    }
    /*
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
    }return -1;
    */
}

void Tower_picker::set_button(int inside_num){
    for(int i=0;i<3;i++){
        button[i][0]=button_origin[i][0];
        button[i][1]=button_origin[i][1];
    }
    if(inside_num==0){
        button[0][0]-=w_expand;
        button[1][1]+=h_expand+h;
        button[2][1]+=h_expand+h*2;
    }else if(inside_num==1){
        button[1][0]-=w_expand;
        button[2][1]+=h_expand+h;
    }else if(inside_num==2){
        button[2][0]-=w_expand;
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
