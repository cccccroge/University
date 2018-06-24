#ifndef BULLET_H
#define BULLET_H

#include <allegro5/allegro.h>
#include <cmath>
#include "global.cpp"

class Bullet
{
public:
    Bullet(int x_pos, int y_pos, ALLEGRO_BITMAP *image,
        int s, int x_d, int y_d, int _range, int _radius, int _damage):
        init_x(x_pos), init_y(y_pos), x(this->init_x), y(this->init_y),
        offset(5), img(image), speed(s), x_dir(x_d), y_dir(y_d),
        range(_range), radius(_radius), damage(_damage) {}
    void draw();
    void move_a_bit();
    bool is_out_of_map();
    bool is_hitting_enemny(int x, int y, int r);
    bool is_out_of_range();

private:
    int x, y;
    int init_x, init_y;
    ALLEGRO_BITMAP *img;
    int offset;
    int speed;
    int x_dir, y_dir;
    int range;
    int radius;
    int damage;
};

#endif // BULLET_H
