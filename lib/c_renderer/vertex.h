#include <stdlib.h>
#include <stdbool.h>

#define UNPROCESSED               0 
#define WORLD_COORDS_CALCULATED   1
#define VIEW_COORDS_CALCULATED    2

#ifndef _VERTEX_DEFINED
#define _VERTEX_DEFINED
typedef struct Vertex {
  float local[4];
  float world[4];
  float view[4];

  uint16_t  int_view_z;

  uint8_t   processed;
  bool      in_frustum;
  uint16_t  screen_x, screen_y;
} Vertex;
#endif

Vertex* new_vertex(float x,float y, float z);
void    free_vertex(Vertex* v);
void    vertex_set_local_coordinates(Vertex* v,float x,float y,float z);
void    vertex_compute_world_coordinates(Vertex* v,float m[static 4][4]);
void    vertex_compute_view_coordinates(Vertex* v,float m[static 4][4]);
void    vertex_reset(Vertex *v);
