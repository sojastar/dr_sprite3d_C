$gtk.ffi_misc.gtk_dlopen("sprite3d")


### SPRITES :
#Sprite*  bridge_new_sprite(float x, float y, float z,int width,int height,int scale,const char* file,int atlas_x,int atlas_y,int atlas_w,int atlas_h);
def new_sprite(x,y,z,width,height,scale,file,atlas_x,atlas_y,atlas_w,atlas_h)
  FFI::Sprite3D_C::bridge_new_sprite(x,y,z,width,height,scale,file,atlas_x,atlas_y,atlas_w,atlas_h)
end


#void     bridge_print_sprite(Sprite* s,int indent);
def print_sprite(s,indent)
  FFI::Sprite3D_C::bridge_print_sprite(s,indent)

#void     bridge_sprite_rotate(Sprite* s,float da);
def sprite_rotate(s,da)
  FFI::Sprite3D_C::bridge_sprite_rotate(s, da)
end

#void     bridge_sprite_rotate_absolute(Sprite* s,float a);
def sprite_rotate_absolute(s,a)
  FFI::Sprite3D_C::bridge_sprite_rotate_absolute(s, a)
end



### BODIES :
#Body*    bridge_new_empty_body(size_t sprite_count);
def new_empty_body(sprite_count)
  FFI::Sprite3D_C::bridge_new_empty_body(sprite_count)
end

#Sprite** bridge_get_body_sprites(Body* b);
def get_body_sprites(b)
  FFI::Sprite3D_C::bridge_get_body_sprites(b)
end

#void     bridge_print_body(Body* b,int indent);
def print_body(b,indent)
  FFI::Sprite3D_C::bridge_print_body(b,indent)
end

#void     bridge_body_move_to(Body* b,float dx,float dy,float dz);
def body_move_to(b,dx,dy,dz)
  FFI::Sprite3D_C::bridge_body_move_to(b, dx, dy, dz)
end

#void     bridge_body_translate(Body* b,float x,float y,float z);
def body_translate(b,x,y,z)
  FFI::Sprite3D_C::bridge_body_translate(b, x, y, z)
end

#void     bridge_body_rotate_x(Body *b,float a);
def body_rotate_x(b,a)
  FFI::Sprite3D_C::bridge_body_rotate_x(b, a)
end

#void     bridge_body_rotate_y(Body *b,float a);
def body_rotate_y(b,a)
  FFI::Sprite3D_C::bridge_body_rotate_y(b, a)
end

#void     bridge_body_rotate_z(Body *b,float a);
def body_rotate_z(b,a)
  FFI::Sprite3D_C::bridge_body_rotate_z(b, a)
end

#void     bridge_body_reset_rotation(Body* b);
def body_reset_rotation(b)
  FFI::Sprite3D_C::bridge_body_reset_rotation(b)
end



### SCENE :
#Scene* bridge_new_scene(void);
def new_scene(void)
  FFI::Sprite3D_C::bridge_new_scene()
end

#void   bridge_scene_push_element(Scene* s,Body* b);
def scene_push_element(s,b)
  FFI::Sprite3D_C::bridge_scene_push_element(s, b)
end

#void   bridge_print_scene(Scene* s,int indent);
def print_scene(s,indent)
  FFI::Sprite3D_C::bridge_print_scene(s,indent)
end



### CAMERA :
#SCamera* bridge_new_camera(float x,float y,float z,float fx,float fy,float fz,float ux,float uy,float uz);
def new_camera(x,y,z,fx,fy,fz,ux,uy,uz)
  FFI::Sprite3D_C::bridge_new_camera(x, y, z, fx, fy, fz, ux, uy, uz)
end

#void     bridge_print_camera(SCamera *camera);
def print_camera(camera)
  FFI::Sprite3D_C::bridge_print_camera(camera)
end

#void     bridge_camera_move_to(SCamera* camera,float x, float y, float z);
def camera_move_to(camera,x,y,z)
  FFI::Sprite3D_C::bridge_camera_move_to(c, x, y, z)
end

#void     bridge_camera_translate(SCamera* camera,float dx, float dy, float dz);
def camera_translate(camera,dx,dy,dz)
  FFI::Sprite3D_C::bridge_camera_translate(camera, dx, dy, dz)
end

#void     bridge_camera_rotate_x(SCamera* camera,float angle);
def camera_rotate_x(camera,angle)
  FFI::Sprite3D_C::bridge_camera_rotate_x(camera, angle)
end

#void     bridge_camera_rotate_y(SCamera* camera,float angle);
def camera_rotate_y(camera,angle)
  FFI::Sprite3D_C::bridge_camera_rotate_y(camera, angle)
end

#void     bridge_camera_rotate_z(SCamera* camera,float angle);
def camera_rotate_z(camera,angle)
  FFI::Sprite3D_C::bridge_camera_rotate_z(camera, angle)
end

#void     bridge_camera_move_forward(SCamera* camera, float speed);
def camera_move_forward(camera,speed)
  FFI::Sprite3D_C::bridge_camera_move_forward(camera, speed)
end

#void     bridge_camera_move_right(SCamera* camera, float speed);
def camera_move_right(camera,speed)
  FFI::Sprite3D_C::bridge_camera_move_right(camera, speed)
end

#void     bridge_camera_move_up(SCamera* camera, float speed);
def camera_move_up(camera,speed)
  FFI::Sprite3D_C::bridge_camera_move_up(camera, speed)
end



### RENDERER :
#Renderer*  bridge_new_renderer(int width,int height,float near,float far);
def new_renderer(width,height,near,far)
  FFI::Sprite3D_C::bridge_new_renderer(width, height, near, far)
end

#void       bridge_render_scene(Renderer* r,SCamera* c,Scene* s);
def renderer_scene(r,c,s)
  FFI::Sprite3D_C::bridge_new_renderer(r,c,s)
end
