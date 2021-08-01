#include <stdlib.h>
#include "matrix.h"
#include "vertex.h"

Vertex* new_vertex(float x,float y,float z) {
  Vertex *v = (Vertex *)malloc(sizeof(Vertex));

  v->local[0]   = x;
  v->local[1]   = y;
  v->local[2]   = z;
  v->local[3]   = 1.0;

  v->world[0]   = 0.0;
  v->world[1]   = 0.0;
  v->world[2]   = 0.0;
  v->world[3]   = 1.0;

  v->view[0]    = 0.0;
  v->view[1]    = 0.0;
  v->view[2]    = 0.0;
  v->view[3]    = 1.0;

  v->processed  = UNPROCESSED;

  return v;
}

void free_vertex(Vertex* v) {
  free(v);
}

void vertex_reset(Vertex *v) {
  v->local[0]   = 0.0;
  v->local[1]   = 0.0;
  v->local[2]   = 0.0;
  v->local[3]   = 1.0;

  v->processed  = UNPROCESSED;
}

void vertex_set_local_coordinates(Vertex* v,float x,float y,float z) {
  v->local[0]   = x;
  v->local[1]   = y;
  v->local[2]   = z;
  v->local[3]   = 1.0;

  v->processed  = UNPROCESSED;
}

void vertex_compute_world_coordinates(Vertex* v,float m[static 4][4]) {
  matrix_vector_mul(m, v->local, v->world);
  v->processed = WORLD_COORDS_CALCULATED;
}

void vertex_compute_view_coordinates(Vertex* v,float m[static 4][4]) {
  matrix_vector_mul(m, v->world, v->view);
  v->int_view_z = (uint16_t)v->view[2];
  v->processed = VIEW_COORDS_CALCULATED;
}
