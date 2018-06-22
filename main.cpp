#include <iostream>
#include <allegro5/allegro.h>

int main()
{
    al_init();

    ALLEGRO_DISPLAY *d = al_create_display(1280, 720);

    while (1) {
        al_clear_to_color(al_map_rgb(128, 128, 128));
        al_flip_display();
    }

    al_destroy_display(d);

    return 0;
}
