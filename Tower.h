#ifndef TOWER_H
#define TOWER_H

#include <allegro5/allegro.h>
#include "Bullet.h"
#include <vector>
#include <cmath>

class Tower
{
public:
    Tower(int grid_x, int grid_y, int img_offset_x, int img_offset_y,
        int img_w, int img_h, int bullet_offset_x, int bullet_offset_y,
        char *t_img_path, char *b_img_path, int range, int rate,
        int speed, int radius, int damage, int fee):
        loc_x(grid_x * 40 + 20), loc_y(grid_y * 40 + 20),
        img_x(this->loc_x + img_offset_x), img_y(this->loc_y + img_offset_y),
        frame_w(img_w), frame_h(img_h),
        bullet_x(this->loc_x + bullet_offset_x),
        bullet_y(this->loc_y + bullet_offset_y),
        fire_range(range), fire_rate(rate),
        bullet_speed(speed), bullet_radius(radius), bullet_damage(damage),
        cost(fee)
    {
        this->tower_img = al_load_bitmap(t_img_path);
        this->bullet_img = al_load_bitmap(b_img_path);
        this->bullets = new std::vector<Bullet*>();
    }
    void fire_bullet(int x_dir, int y_dir);
    void upgrade();
    void draw();
    bool is_entering_range(int x, int y, int r);
    bool is_upgrading();
    int get_loc_x() { return this->loc_x; }
    int get_loc_y() { return this->loc_y; }
    std::vector<Bullet*>* get_bullets() { return this->bullets; }

private:
    int loc_x, loc_y;
    int img_x, img_y;
    int frame_w, frame_h;
    int bullet_x, bullet_y;
    ALLEGRO_BITMAP *tower_img;
    ALLEGRO_BITMAP *bullet_img;
    int fire_range;
    int fire_rate;
    int bullet_speed;
    int bullet_radius;
    int bullet_damage;
    int cost;
    std::vector<Bullet*> *bullets;
};

#endif // TOWER_H
