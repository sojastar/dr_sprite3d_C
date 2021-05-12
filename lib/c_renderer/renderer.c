#include <stdio.h>
#include <math.h>
#include "renderer.h"
#include "counting_sort.h"
#include "radix_sort.h"

Renderer* new_renderer(uint16_t width,uint16_t height,float near, float far,size_t max_sprites) {
  Renderer* renderer = (Renderer *)malloc(sizeof(Renderer));

  printf("in new_renderer: renderer=%p\n", renderer);

  renderer->width               = width;
  renderer->height              = height;
  renderer->half_width          = width >> 1;
  renderer->half_height         = height >> 1;
  renderer->ratio               = (float)width / height;
  renderer->near                = near;
  renderer->far                 = far;
  renderer->in_frustum_sprites  = (Sprite**)malloc(max_sprites * sizeof(Sprite*));
  renderer->sorted_sprites      = (Sprite**)malloc(max_sprites * sizeof(Sprite*));

  printf( "in new_renderer: max_sprites=%zu - in_frustum_sprites=%p - sorted_sprites=%p\n",
          max_sprites,
          renderer->in_frustum_sprites,
          renderer->sorted_sprites );

  return renderer;
}

void free_renderer(Renderer *renderer) {
  free(renderer->in_frustum_sprites);
  free(renderer->sorted_sprites);
  free(renderer);
}

void print_renderer(Renderer *renderer) {
  printf("=== Renderer : ===\n");
  printf("- width x height: (%hu;%hu)\n", renderer->width, renderer->height);
  printf("- far plane:      %f\n", renderer->far);
  printf("- near plane:     %f\n", renderer->near);
}

bool is_vertex_in_frustum(Renderer* renderer,Vertex* vertex) {
  float x = vertex->view[0];
  float y = vertex->view[1];
  float z = vertex->view[2];
      
  return  (       z > renderer->near            ) &&
          (       z < renderer->far             ) &&
          ( fabs(z) > fabs(x)                   ) &&
          ( fabs(z) > renderer->ratio * fabs(y) );
}

void project_vertex(Renderer* renderer,SCamera* camera,Vertex* vertex) {
  compute_view_coordinates(vertex, camera->view_matrix);

  if (is_vertex_in_frustum(renderer, vertex)) {
    vertex->screen_x   = renderer->half_width  + (int)(                  renderer->half_width * vertex->view[0] / vertex->view[2]);
    //vertex->screen_y   = renderer->half_height + (int)(renderer->ratio * renderer->half_width * vertex->view[1] / vertex->view[2]);
    vertex->screen_y   = renderer->half_height + (int)( renderer->half_width * vertex->view[1] / vertex->view[2]);
    vertex->in_frustum = true;
  }
  else {
    vertex->in_frustum = false;
  }
}

void render_scene(Renderer* renderer,SCamera* camera,Scene* scene) {
  camera_reset_view_matrix(camera);
  camera_compute_view_matrix(camera);

  Element* current = scene->first;
  renderer->in_frustum_sprites_count  = 0;
  while(current != (void*)0) {
    Body* body  = current->body;
    for(size_t i = 0; i < body->sprite_count; ++i) {
      Sprite* sprite  = body->sprites[i];
      Vertex* vertex  = sprite->vertex;

      compute_world_coordinates(vertex, body->world);
      project_vertex(renderer, camera, vertex);

      if (vertex->in_frustum) {
        sprite_compute_draw_size(sprite);

        renderer->in_frustum_sprites[renderer->in_frustum_sprites_count] = sprite;
        renderer->in_frustum_sprites_count += 1;
      }
    }

    current     = current->next; 
  }
  
  counting_sort(renderer->in_frustum_sprites_count, renderer->in_frustum_sprites, renderer->sorted_sprites);
  //radix_sort(renderer->in_frustum_sprites_count, renderer->in_frustum_sprites, renderer->sorted_sprites);
}

size_t sprites_in_frustum_count(Renderer* renderer) {
  return renderer->in_frustum_sprites_count;
}

size_t sorted_sprites_count(Renderer* renderer) {
  return renderer->in_frustum_sprites_count;
}
