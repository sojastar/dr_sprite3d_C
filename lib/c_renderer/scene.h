#include <stddef.h>
#include "body.h"

#ifndef _ELEMENT_DEFINED
#define _ELEMENT_DEFINED
typedef struct Element Element;

struct Element {
  Element*  previous;
  Element*  next;
  Body*     body;
};
#endif

#ifndef _SCENE_DEFINED
#define _SCENE_DEFINED
typedef struct Scene {
  size_t    element_count;
  size_t    sprite_count;
  Element*  first;
  Element*  last;
} Scene;
#endif

Scene*  new_scene(void);
void    free_scene(Scene* s);
void    print_scene(Scene* s,int indent);
void    scene_push_element(Scene* s,Body* b);
size_t  scene_get_element_count(Scene* s);
size_t  scene_get_sprite_count(Scene* s);
