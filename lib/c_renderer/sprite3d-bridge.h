#include <stddef.h>

/* ---=== SPRITE : ====--- */
typedef struct Sprite Sprite;

extern Sprite*  bridge_new_sprite(float x, float y, float z,int width,int height,int scale,const char* file,int atlas_x,int atlas_y,int atlas_w,int atlas_h);
extern void     bridge_sprite_rotate(Sprite* s,float da);
extern void     bridge_sprite_rotate_absolute(Sprite* s,float a);


/* ---=== BODY : ===--- */
typedef struct Body Body;

extern Body*    bridge_new_empty_body(size_t sprite_count);
extern Sprite** bridge_get_body_sprites(Body* b);
extern void     bridge_body_move_to(Body* b,float dx,float dy,float dz);
extern void     bridge_body_translate(Body* b,float x,float y,float z);
extern void     bridge_body_rotate_x(Body *b,float a);
extern void     bridge_body_rotate_y(Body *b,float a);
extern void     bridge_body_rotate_z(Body *b,float a);
extern void     bridge_body_reset_rotation(Body* b);


/* ---=== SCENE : ===--- */
typedef struct Scene Scene;

extern Scene* bridge_new_scene(void);
extern void   bridge_scene_push_element(Scene* s,Body* b);


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

extern Renderer*  bridge_new_renderer(int width,int height,float near,float far);
extern void       bridge_render_scene(Renderer* r,SCamera* c,Scene* s);
