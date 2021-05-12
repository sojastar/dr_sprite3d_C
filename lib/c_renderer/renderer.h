#include <stdlib.h>
#include "vertex.h"
#include "sprite.h"
#include "camera.h"
#include "scene.h"

typedef struct Renderer {
      uint16_t  width;
      uint16_t  height;
      uint16_t  half_width;
      uint16_t  half_height;
      float     ratio;
      float     near;
      float     far;
      size_t    in_frustum_sprites_count;
      Sprite**  in_frustum_sprites;
      Sprite**  sorted_sprites;
} Renderer;

Renderer* new_renderer(uint16_t width,uint16_t height,float near,float far,size_t max_sprites);
void      free_renderer(Renderer* r);
void      print_renderer(Renderer* r);
bool      is_vertex_in_frustum(Renderer* r,Vertex* vertex);
void      project_vertex(Renderer* r,SCamera* c,Vertex* vertex);
void      render_scene(Renderer* r,SCamera* c,Scene* s);
size_t    sprites_in_frustum_count(Renderer* renderer);
size_t    sorted_sprites_count(Renderer* renderer);
