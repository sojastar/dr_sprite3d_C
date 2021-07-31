#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "sprite.h"

Sprite* new_sprite(Vertex* vertex,uint16_t width,uint16_t height,uint16_t scale,uint16_t file_index,uint16_t atlas_x,uint16_t atlas_y,uint16_t atlas_w,uint16_t atlas_h) {
  Sprite *s = (Sprite *)malloc(sizeof(Sprite));

  s->vertex                         = vertex;

  s->render_data[WIDTH]             = scale * width;
  s->render_data[HEIGHT]            = scale * height;
  s->render_data[SCALE]             = scale;
  s->render_data[DRAW_X]            = 1280;
  s->render_data[DRAW_Y]            = 720;
  s->render_data[DRAW_WIDTH]        = scale * width;
  s->render_data[DRAW_HEIGHT]       = scale * height;
  s->render_data[ANGLE]             = 0;
  s->render_data[ATLAS_FILE_INDEX]  = file_index;
  s->render_data[ATLAS_X]           = atlas_x;
  s->render_data[ATLAS_Y]           = atlas_y;
  s->render_data[ATLAS_W]           = atlas_w;
  s->render_data[ATLAS_H]           = atlas_h;

  return s;
}

void free_sprite(Sprite* s) {
  free(s->vertex);
  free(s);
}

void print_sprite(Sprite* s,int indent) {
  printf("%*s--- Sprite : ---\n", indent, "");
  printf("%*slocal position:  (%.3f;%.3f;%.3f)\n", indent, "", s->vertex->local[0], s->vertex->local[1], s->vertex->local[2]);
  printf("%*sworld position:  (%.3f;%.3f;%.3f)\n", indent, "", s->vertex->world[0], s->vertex->world[1], s->vertex->world[2]);
  printf("%*sview position:   (%.3f;%.3f;%.3f)\n", indent, "", s->vertex->view[0], s->vertex->view[1], s->vertex->view[2]);
  printf("%*sdraw x and y:    (%d;%d)\n", indent, "", s->render_data[DRAW_X], s->render_data[DRAW_Y]);
  printf("%*sdraw width:      (%d;%d)\n", indent, "", s->render_data[DRAW_WIDTH], s->render_data[DRAW_HEIGHT]);
  //printf("%*sangle:           %.3f\n", indent, "", s->render_data[ANGLE]);
  printf("%*sangle:           %d\n", indent, "", s->render_data[ANGLE]);
  printf("%*sfile index:      %d\n", indent, "", s->render_data[ATLAS_FILE_INDEX]);
  printf("%*satlas positon:   (%d;%d;%d;%d)\n", indent, "", s->render_data[ATLAS_X], s->render_data[ATLAS_Y], s->render_data[ATLAS_W], s->render_data[ATLAS_H]);
}

void sprite_compute_draw_size(Sprite* s) {
  s->render_data[DRAW_WIDTH]  = (int)( s->render_data[WIDTH] / s->vertex->view[2]);
  s->render_data[DRAW_HEIGHT] = (int)(s->render_data[HEIGHT] / s->vertex->view[2]);
  s->render_data[DRAW_X]      = (int)(s->vertex->screen_x - (s->render_data[DRAW_WIDTH]  >> 1));
  s->render_data[DRAW_Y]      = (int)(s->vertex->screen_y - (s->render_data[DRAW_HEIGHT] >> 1));
}

//void sprite_rotate(Sprite* s,float da) {
void sprite_rotate(Sprite* s,int da) {
  //s->angle = fmod(s->angle + da, 360.0);
  s->render_data[ANGLE] = ( s->render_data[ANGLE] + da ) % 360;
}

//void sprite_rotate_absolute(Sprite* s,float a) {
void sprite_rotate_absolute(Sprite* s,int a) {
  //s->angle = fmod(a, 360.0);
  s->render_data[ANGLE] = a % 360;
}
