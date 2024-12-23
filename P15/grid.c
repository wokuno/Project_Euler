#include <stdio.h>
#include <stdlib.h>
#include "grid.h"
#include <inttypes.h>

void grid_init(grid *g, int width, int height) {
    g->width = width;
    g->height = height;
    g->squares = malloc(width * height * sizeof(square));
}

void grid_free(grid *g) {
    free(g->squares);
}

void grid_set(grid *g, int x, int y, int edges) {
    g->squares[y * g->width + x].edges = edges;
}

void grid_print_no_cursor(grid *g) {
    // clear screen
    printf("\033[2J");

    for (int y = 0; y < g->height; y++) {
        for (int x = 0; x < g->width; x++) {
            square s = g->squares[y * g->width + x];
            if (y == 0) {
                if (s.edges & TOP) {
                    printf("+--");
                } else {
                    printf("+  ");
                }
            } else {
                square s2 = g->squares[(y - 1) * g->width + x];
                if ((s.edges & TOP) || (s2.edges & BOTTOM)) {
                    printf("+--");
                } else {
                    printf("+  ");
                }
            }
        }
        printf("+\n");

        for (int x = 0; x < g->width; x++) {
            square s = g->squares[y * g->width + x];
            if (x == 0) {
                if (s.edges & LEFT) {
                    printf("| ");
                } else {
                    printf("  ");
                }
            } else if (x <= g->width - 1) {
                square s2 = g->squares[y * g->width + x - 1];
                if ((s.edges & LEFT) || (s2.edges & RIGHT)) {
                    printf("| ");
                } else {
                    printf("  ");
                }
            }
            if (x == g->width - 1) {
                if (s.edges & RIGHT) {
                    printf("|");
                } else {
                    printf(" ");
                }
            } else {
                printf(" ");
            }
        }

        printf("\n");
    }
    for (int x = 0; x < g->width; x++) {
        square s = g->squares[(g->height - 1) * g->width + x];
        if (s.edges & BOTTOM) {
            printf("+--");
        } else {
            printf("+  ");
        }
    }
    printf("+\n");
}

void grid_print_cursor(grid *g, cursor c){
    // clear screen
    printf("\033[2J");

    for (int y = 0; y < g->height; y++) {
        for (int x = 0; x < g->width; x++) {
            square s = g->squares[y * g->width + x];
            printf("+");
            if (x == c.x && y == c.y && c.dir == TOP) {
                // set color to red
                printf("\033[0;31m");
                s.edges |= TOP;
            }
            if (y == 0) {
                if (s.edges & TOP) {
                    printf("--");
                } else {
                    printf("  ");
                }
            } else {
                square s2 = g->squares[(y - 1) * g->width + x];
                if ((s.edges & TOP) || (s2.edges & BOTTOM)) {
                    printf("--");
                } else {
                    printf("  ");
                }
            }
            // reset color
            if (x == c.x && y == c.y && c.dir == TOP) {
                printf("\033[0m");
            }
        }
        printf("+\n");
        for (int x = 0; x < g->width; x++) {
            square s = g->squares[y * g->width + x];
            if (x == c.x && y == c.y && c.dir == LEFT) {
                // set color to red
                printf("\033[0;31m");
                s.edges |= LEFT;
            }
            if (x == 0) {
                if (s.edges & LEFT) {
                    printf("| ");
                } else {
                    printf("  ");
                }
            } else if (x <= g->width - 1) {
                square s2 = g->squares[y * g->width + x - 1];
                if ((s.edges & LEFT) || (s2.edges & RIGHT)) {
                    printf("| ");
                } else {
                    printf("  ");
                }
            }
            // reset color
            if (x == c.x && y == c.y && c.dir == LEFT) {
                printf("\033[0m");
            }
            if (x == g->width - 1) {
                if (x == c.x && y == c.y && c.dir == RIGHT) {
                    // set color to red
                    printf("\033[0;31m");
                    s.edges |= RIGHT;
                }
                if (s.edges & RIGHT) {
                    printf("|");
                } else {
                    printf(" ");
                }
                // reset color
                if (x == c.x && y == c.y && c.dir == RIGHT) {
                    printf("\033[0m");
                }
            } else {
                printf(" ");
            }
        }

        printf("\n");
    }
    for (int x = 0; x < g->width; x++) {
        square s = g->squares[(g->height - 1) * g->width + x];
        if (x == c.x && c.dir == BOTTOM) {
            // set color to red
            printf("\033[0;31m");
            s.edges |= BOTTOM;
        }
        if (s.edges & BOTTOM) {
            printf("+--");
        } else {
            printf("+  ");
        }
        // reset color
        if (x == c.x && c.dir == BOTTOM) {
            printf("\033[0m");
        }
    }
    printf("+\n");
}

void grid_move_cursor(grid *g, cursor *c, int dir) {
    if (dir == c->dir){
        switch (dir) {
            case TOP:
                if (c->y > 0) {
                    c->y--;
                }
                break;
            case RIGHT:
                if (c->x < g->width - 1) {
                    c->x++;
                }
                break;
            case BOTTOM:
                if (c->y < g->height - 1) {
                    c->y++;
                }
                break;
            case LEFT:
                if (c->x > 0) {
                    c->x--;
                }
                break;
        }
    }
    c->dir = dir;
}