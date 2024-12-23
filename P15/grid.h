// edges of a square are represented by 4 bits, 1 for each edge
#define TOP 0b0001
#define RIGHT 0b0010
#define BOTTOM 0b0100
#define LEFT 0b1000

#define UP TOP
#define DOWN BOTTOM 

typedef struct{
    int edges;
} square;

typedef struct{
    square *squares;
    int width;
    int height;
} grid;

typedef struct
{
    int x;
    int y;
    int dir;
} cursor;

void grid_init(grid *g, int width, int height);
void grid_free(grid *g);
void grid_set(grid *g, int x, int y, int edges);
void grid_print_no_cursor(grid *g);
void grid_print_cursor(grid *g, cursor c);
#define grid_print(g) grid_print_no_cursor(g)
void grid_move_cursor(grid *g, cursor *c, int dir);