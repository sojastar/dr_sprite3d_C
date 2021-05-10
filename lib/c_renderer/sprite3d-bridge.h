//#include <stdint.h>
//#include <stddef.h>

/* ---=== SPRITE : ====--- */
typedef struct Sprite Sprite;

extern Sprite*      bridge_new_sprite(float x, float y, float z,int width,int height,int scale,const char* file,int atlas_x,int atlas_y,int atlas_w,int atlas_h);
extern void         bridge_print_sprite(Sprite* s,int indent);
extern void         bridge_sprite_rotate(Sprite* s,float da);
extern void         bridge_sprite_rotate_absolute(Sprite* s,float a);
extern int          bridge_sprite_get_draw_x(Sprite* s);
extern int          bridge_sprite_get_draw_y(Sprite* s);
extern int          bridge_sprite_get_draw_w(Sprite* s);
extern int          bridge_sprite_get_draw_h(Sprite* s);
extern const char*  bridge_sprite_get_atlas_file(Sprite* s);
extern int          bridge_sprite_get_atlas_x(Sprite* s);
extern int          bridge_sprite_get_atlas_y(Sprite* s);
extern int          bridge_sprite_get_atlas_w(Sprite* s);
extern int          bridge_sprite_get_atlas_h(Sprite* s);


/* ---=== BODY : ===--- */
typedef struct Body Body;

extern Body*    bridge_new_empty_body(int sprite_count);
extern Sprite** bridge_get_body_sprites(Body* b);
extern void     bridge_print_body(Body* b,int indent);
extern void     bridge_body_move_to(Body* b,float x,float y,float z);
extern void     bridge_body_translate(Body* b,float dx,float dy,float dz);
extern void     bridge_body_rotate_x(Body* b,float a);
extern void     bridge_body_rotate_y(Body* b,float a);
extern void     bridge_body_rotate_z(Body* b,float a);
extern void     bridge_body_reset_rotation(Body* b);


/* ---=== SCENE : ===--- */
typedef struct Scene Scene;

extern Scene* bridge_new_scene(void);
extern void   bridge_scene_push_element(Scene* s,Body* b);
extern void   bridge_print_scene(Scene* s,int indent);
extern int    bridge_scene_get_element_count(Scene* s);
extern int    bridge_scene_get_sprite_count(Scene* s);


/* ---=== CAMERA : ===--- */
typedef struct SCamera SCamera;

extern SCamera* bridge_new_camera(float x, float y, float z,float fx, float fy, float fz,float ux, float uy, float uz);
extern void     bridge_print_camera(SCamera *camera);
extern void     bridge_camera_move_to(SCamera* camera,float x, float y, float z);
extern void     bridge_camera_translate(SCamera* camera,float dx, float dy, float dz);
extern void     bridge_camera_rotate_x(SCamera* camera,float angle);
extern void     bridge_camera_rotate_y(SCamera* camera,float angle);
extern void     bridge_camera_rotate_z(SCamera* camera,float angle);
extern void     bridge_camera_move_forward(SCamera* camera, float speed);
extern void     bridge_camera_move_right(SCamera* camera, float speed);
extern void     bridge_camera_move_up(SCamera* camera, float speed);


/* ---=== RENDERER : ===--- */
typedef struct Renderer Renderer;

extern Renderer*  bridge_new_renderer(int width,int height,float near,float far,int max_sprites);
extern void       bridge_print_renderer(Renderer* r);
extern void       bridge_render_scene(Renderer* r,SCamera* c,Scene* s);
extern Sprite**   bridge_renderer_get_sorted_sprites(Renderer* r);
extern int        bridge_renderer_get_sorted_sprites_count(Renderer* r);
