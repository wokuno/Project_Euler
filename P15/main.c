#include "grid.h"
#include <stdio.h>
#include <unistd.h>

int main() {
    grid g;
    cursor c;
    grid_init(&g, 20, 20);
    // grid_set(&g, 0, 0, TOP | LEFT);
    grid_set(&g, 1, 0, TOP | RIGHT);
    grid_set(&g, 10, 10, TOP | LEFT | RIGHT | BOTTOM);
    grid_print(&g);

    c.x = 0;
    c.y = 0;
    c.dir = TOP;

    grid_print_cursor(&g, c);

    // delay for 1 second
    usleep(1000000);

    c.dir = LEFT;
    grid_print_cursor(&g, c);

    grid_free(&g);
    return 0;
}