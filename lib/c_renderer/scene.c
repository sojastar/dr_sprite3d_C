#include <stdlib.h>
#include <stdio.h>
#include "scene.h"

Scene* new_scene(void) {
  Scene* s = (Scene *)malloc(sizeof(Scene));

  s->element_count  = 0;
  s->sprite_count   = 0;
  s->first          = (void*)0;
  s->last           = (void*)0;

  return s;
}

void free_scene(Scene* s) {
  Element* current;
  Element* next;
  
  current = s->first;
  while(current != (void*)0) {
    next    = current->next;

    free(current->body);
    free(current);

    current = next;
  }

  free(s);
}

void print_scene(Scene* s,int indent) {
  Element* current;
  Element* next;
  
  printf("%*s--= Scene : =--\n", indent, "");

  current = s->first;
  while(current != (void*)0) {
    next    = current->next;
    print_body(current->body, indent + 1);
    current = next;
  }
}

void scene_push_element(Scene* s,Body* b) {
  Element* e = (Element*)malloc(sizeof(Element));

  e->body     = b;
  e->previous = s->last;
  e->next     = (void*)0;

  if(s->element_count == 0)
    s->first        = e;
  s->last           = e;
  s->element_count += 1;
  s->sprite_count  += b->sprite_count;
}

size_t scene_get_element_count(Scene* s) {
  return s->element_count;
}

size_t scene_get_sprite_count(Scene* s) {
  return s->sprite_count;
}
