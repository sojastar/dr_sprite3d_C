#include "sprite3d-bridge.h"
#include "sprite.h"
#include "body.h"
#include "scene.h"
#include "camera.h"
#include "renderer.h"

/* ---=== SPRITE : ====--- */
Sprite*  bridge_new_sprite(float x, float y, float z,int width,int height,int scale,const char* file,int atlas_x,int atlas_y,int atlas_w,int atlas_h) {
  Vertex* vertex  = new_vertex(x, y, z);
  return new_sprite(vertex, width, height, scale, file, atlas_x, atlas_y, atlas_w, atlas_h);
}

void bridge_sprite_rotate(Sprite* s,float da) {
  sprite_rotate(s, da);
}

void bridge_sprite_rotate_absolute(Sprite* s,float a) {
  sprite_rotate_absolute(s, a);
}





/* ---=== BODY : ===--- */
Body* bridge_new_empty_body(size_t sprite_count) {
  return new_empty_body(sprite_count);
}

Sprite** bridge_get_body_sprites(Body* b) {
  return get_body_sprites(b);
}

void bridge_body_move_to(Body* b,float x,float y,float z) {
  body_move_to(b, x, y, z);
}

void bridge_body_translate(Body* b,float dx,float dy,float dz) {
  body_translate(b, dx, dy, dz);
}

void bridge_body_rotate_x(Body *b,float a) {
  body_rotate_x(b, a);
}

void bridge_body_rotate_y(Body *b,float a) {
  body_rotate_y(b, a);
}

void bridge_body_rotate_z(Body *b,float a) {
  body_rotate_z(b, a);
}

void bridge_body_reset_rotation(Body* b) {
  body_reset_rotation(b);
}





/* ---=== SCENE : ===--- */
Scene* bridge_new_scene(void) {
  return new_scene();
}

void bridge_scene_push_element(Scene* s,Body* b) {
  scene_push_element(s, b);
}





/* ---=== CAMERA : ===--- */
SCamera* bridge_new_camera(float x, float y, float z,float fx, float fy, float fz,float ux, float uy, float uz) {  
  float position[4]  = {  x,  y,  z, 1.0 };
  float forward[4]   = { fx, fy, fz, 1.0 };
  float up[4]        = { ux, uy, uz, 1.0 };

  return new_camera(position, forward, up);
}

void bridge_print_camera(SCamera *camera) {
  print_camera(camera);
}

void bridge_camera_move_to(SCamera* camera,float x, float y, float z) {
  float position[] = { x, y, z, 1.0 };
  camera_move_to(camera, position);
}

void bridge_camera_translate(SCamera* camera,float dx, float dy, float dz) {
  float offset[] = { dx, dy, dz, 1.0 };
  camera_translate(camera, offset);
}

void bridge_camera_rotate_x(SCamera* camera,float angle) {
  camera_rotate_x(camera, angle);
}

void bridge_camera_rotate_y(SCamera* camera,float angle) {
  camera_rotate_y(camera, angle);
}
void bridge_camera_rotate_z(SCamera* camera,float angle) {
  camera_rotate_z(camera, angle);
}

void bridge_camera_move_forward(SCamera* camera, float speed) {
  camera_move_forward(camera, speed);
}

void bridge_camera_move_right(SCamera* camera, float speed) {
  camera_move_right(camera, speed);
}

void bridge_camera_move_up(SCamera* camera, float speed) {
  camera_move_up(camera, speed);
}





/* ---=== RENDERER : ===--- */
Renderer* bridge_new_renderer(int width,int height,float near,float far) {
  return new_renderer(width, height, near, far);
}

void bridge_render_scene(Renderer* r,SCamera* c,Scene* s) {
  render_scene(r, c, s);
}
