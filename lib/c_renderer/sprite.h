#include <stddef.h>
#include "vertex.h"

#define WIDTH             0
#define HEIGHT            1
#define SCALE             2
#define DRAW_X            3
#define DRAW_Y            4
#define DRAW_WIDTH        5
#define DRAW_HEIGHT       6
#define ANGLE             7
#define ATLAS_FILE_INDEX  8
#define ATLAS_X           9
#define ATLAS_Y           10
#define ATLAS_W           11
#define ATLAS_H           12

#ifndef _SPRITE_DEFINED
#define _SPRITE_DEFINED
typedef struct Sprite {
  Vertex      *vertex;
  int         render_data[14];
} Sprite;
#endif

Sprite* new_sprite(Vertex* v,uint16_t width,uint16_t height,uint16_t scale,uint16_t file_index,uint16_t atlas_x,uint16_t atlas_y,uint16_t atlas_w,uint16_t atlas_h);
void    free_sprite(Sprite* s);
void    print_sprite(Sprite* s,int indent);
void    sprite_compute_draw_size(Sprite* s);
//void    sprite_rotate(Sprite* s,float da);
void    sprite_rotate(Sprite* s,int da);
//void    sprite_rotate_absolute(Sprite* s,float a);
void    sprite_rotate_absolute(Sprite* s,int a);
