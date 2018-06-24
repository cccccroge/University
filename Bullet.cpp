#include "Bullet.h"

void Bullet::draw()
{
    int d = this->offset;
    al_draw_bitmap(this->img, this->x - d , this->y - d, 0);
}

void Bullet::move_a_bit()
{
    int a = this->x_dir;
    int b = this->y_dir;
    double c = std::pow(std::pow(a, 2) + std::pow(b, 2), 1/2);

    double factor = this->speed / GAME_FPS;
    double dx = a / c * factor;
    double dy = b / c * factor;

    this->x += round(dx);
    this->y += round(dy);
}

bool Bullet::is_out_of_map()
{
    return (this->x > LEVEL_WIDTH || this->y > LEVEL_HEIGHT);
}

bool Bullet::is_hitting_enemny(int x, int y, int r)
{
    int dx = std::abs(x - this->x);
    int dy = std::abs(y - this->y);
    int distance = std::pow(std::pow(dx, 2) + std::pow(dy, 2), 1/2);

    return (distance <= r + this->radius);
}

bool Bullet::is_out_of_range()
{
    int dx = std::abs(this->x - this->init_x);
    int dy = std::abs(this->y - this->init_y);
    int distance = std::pow(std::pow(dx, 2) + std::pow(dy, 2), 1/2);

    return (distance > this->range);
}
