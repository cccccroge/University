#include "Tower.h"

void Tower::fire_bullet(int x_dir, int y_dir)
{
    this->bullets->push_back(new Bullet(
        this->bullet_x, this->bullet_y, this->bullet_img,
        this->bullet_speed, x_dir, y_dir,
        this->fire_range, this->bullet_radius, this->bullet_damage));
}

void Tower::draw()
{
    // draw tower itself
    al_draw_bitmap(this->tower_img, this->img_x, this->img_y, 0);

    // iterate bullets vector and draw individual bullet
    for (std::vector<Bullet*>::iterator b = this->bullets->begin();
         b != this->bullets->end(); b++) {
        (*b)->draw();
    }
}

bool Tower::is_entering_range(int x, int y, int r)
{
    int dx = std::abs(x - this->bullet_x);
    int dy = std::abs(y - this->bullet_y);
    int distance = std::pow(std::pow(dx, 2) + std::pow(dy, 2), 1/2);

    return (distance <= r + this->fire_range);
}
