#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include "dragonruby.h"
#include "sprite3d-bridge.h"
#include "matrix.h"
#include "vertex.h"
#include "sprite.h"
#include "body.h"
#include "scene.h"
#include "camera.h"
#include "renderer.h"

/* ---=== VERTEX : ====--- */
DRB_FFI
Vertex* bridge_new_vertex(float x,float y, float z) {
  return new_vertex(x, y, z);
}

DRB_FFI
void bridge_compute_world_coordinates(Vertex* v,Body* b) {
  compute_world_coordinates(v, b->world);
}

DRB_FFI
void bridge_compute_view_coordinates(Vertex* v,SCamera* c) {
  matrix_vector_mul(c->view_matrix, v->world, v->view);
  v->int_view_z = (uint16_t)v->view[2];
  v->processed = VIEW_COORDS_CALCULATED;
}

DRB_FFI
void bridge_vertex_reset(Vertex *v) {
  vertex_reset(v);
}





/* ---=== SPRITE : ====--- */
DRB_FFI
Sprite* bridge_new_sprite(float x, float y, float z,int width,int height,int scale,int file_index,int atlas_x,int atlas_y,int atlas_w,int atlas_h) {
  Vertex* vertex  = new_vertex(x, y, z);
  return new_sprite(vertex, (uint16_t)width, (uint16_t)height, (uint16_t)scale, (uint16_t)file_index, (uint16_t)atlas_x, (uint16_t)atlas_y, (uint16_t)atlas_w, (uint16_t)atlas_h);
}

DRB_FFI
void bridge_print_sprite(Sprite* s,int indent) {
  print_sprite(s, indent);
}

DRB_FFI
//void bridge_sprite_rotate(Sprite* s,float da) {
void bridge_sprite_rotate(Sprite* s,int da) {
  sprite_rotate(s, da);
}

DRB_FFI
//void bridge_sprite_rotate_absolute(Sprite* s,float a) {
void bridge_sprite_rotate_absolute(Sprite* s,int a) {
  sprite_rotate_absolute(s, a);
}

DRB_FFI
int* bridge_sprite_get_render_data(Sprite* s) {
  return s->render_data;
}





/* ---=== BODY : ===--- */
DRB_FFI
Body* bridge_new_empty_body(int sprite_count) {
  return new_empty_body((size_t)sprite_count);
}

DRB_FFI
Sprite** bridge_get_body_sprites(Body* b) {
  return get_body_sprites(b);
}

DRB_FFI
void bridge_print_body(Body* b,int indent) {
  print_body(b, indent);
}

DRB_FFI
void bridge_body_move_to(Body* b,float x,float y,float z) {
  body_move_to(b, x, y, z);
}

DRB_FFI
void bridge_body_translate(Body* b,float dx,float dy,float dz) {
  body_translate(b, dx, dy, dz);
}

DRB_FFI
void bridge_body_rotate_x(Body* b,float a) {
  body_rotate_x(b, a);
}

DRB_FFI
void bridge_body_rotate_y(Body* b,float a) {
  body_rotate_y(b, a);
}

DRB_FFI
void bridge_body_rotate_z(Body* b,float a) {
  body_rotate_z(b, a);
}

DRB_FFI
void bridge_body_reset_rotation(Body* b) {
  body_reset_rotation(b);
}





/* ---=== SCENE : ===--- */
DRB_FFI
Scene* bridge_new_scene(void) {
  return new_scene();
}

DRB_FFI
void bridge_scene_push_element(Scene* s,Body* b) {
  scene_push_element(s, b);
}

DRB_FFI
void bridge_print_scene(Scene* s,int indent) {
  print_scene(s, indent);
}

DRB_FFI
int bridge_scene_get_element_count(Scene* s) {
  return (int)scene_get_element_count(s);
}

DRB_FFI
int bridge_scene_get_sprite_count(Scene* s) {
  return (int)scene_get_sprite_count(s);
}





/* ---=== CAMERA : ===--- */
DRB_FFI
SCamera* bridge_new_camera(float x, float y, float z,float fx, float fy, float fz,float ux, float uy, float uz) {  
  float position[4]  = {  x,  y,  z, 1.0 };
  float forward[4]   = { fx, fy, fz, 1.0 };
  float up[4]        = { ux, uy, uz, 1.0 };

  return new_camera(position, forward, up);
}

DRB_FFI
void bridge_print_camera(SCamera *camera) {
  print_camera(camera);
}

DRB_FFI
void bridge_camera_move_to(SCamera* camera,float x, float y, float z) {
  float position[] = { x, y, z, 1.0 };
  camera_move_to(camera, position);
}

DRB_FFI
void bridge_camera_translate(SCamera* camera,float dx, float dy, float dz) {
  float offset[] = { dx, dy, dz, 1.0 };
  camera_translate(camera, offset);
}

DRB_FFI
void bridge_camera_rotate_x(SCamera* camera,float angle) {
  camera_rotate_x(camera, angle);
}

DRB_FFI
void bridge_camera_rotate_y(SCamera* camera,float angle) {
  camera_rotate_y(camera, angle);
}

DRB_FFI
void bridge_camera_rotate_z(SCamera* camera,float angle) {
  camera_rotate_z(camera, angle);
}

DRB_FFI
void bridge_camera_move_forward(SCamera* camera,float speed) {
  camera_move_forward(camera, speed);
}

DRB_FFI
void bridge_camera_move_right(SCamera* camera,float speed) {
  camera_move_right(camera, speed);
}

DRB_FFI
void bridge_camera_move_up(SCamera* camera,float speed) {
  camera_move_up(camera, speed);
}





/* ---=== RENDERER : ===--- */
DRB_FFI
Renderer* bridge_new_renderer(int width,int height,float near,float far,int max_sprites) {
  return new_renderer((uint16_t)width, (uint16_t)height, near, far, (size_t)max_sprites);
}

DRB_FFI
void bridge_print_renderer(Renderer* renderer) {
  print_renderer(renderer);
}

DRB_FFI
void bridge_render_scene(Renderer* renderer,SCamera* camera,Scene* scene) {
  render_scene(renderer, camera, scene);
}

DRB_FFI
Sprite** bridge_renderer_get_sorted_sprites(Renderer* renderer) {
  return renderer->sorted_sprites;
}

DRB_FFI
int bridge_renderer_get_sorted_sprites_count(Renderer* renderer) {
  return (int)sorted_sprites_count(renderer);
}
