$gtk.ffi_misc.gtk_dlopen("sprite3d")

module Engine3D
  ### SPRITES :
  def self.new_sprite(x,y,z,width,height,scale,file,atlas_x,atlas_y,atlas_w,atlas_h)
    FFI::Sprite3D_C::bridge_new_sprite(x,y,z,width,height,scale,file,atlas_x,atlas_y,atlas_w,atlas_h)
  end
  
  def self.print_sprite(s,indent)
    FFI::Sprite3D_C::bridge_print_sprite(s,indent)
  end


  ### BODIES :
  class Body
    attr_reader :c_body

    def initialize(sprites)
      @c_body   = FFI::Sprite3D_C::bridge_new_empty_body(sprites.length)

      c_sprites = FFI::Sprite3D_C::bridge_get_body_sprites(@c_body)
      sprites.each.with_index { |s,i| c_sprites[i] = s }
    end
    
    def body_sprites
      FFI::Sprite3D_C::bridge_get_body_sprites(@c_body)
    end
    
    def print(indent)
      FFI::Sprite3D_C::bridge_print_body(@c_body,indent)
    end
    
    def move_to(x,y,z)
      FFI::Sprite3D_C::bridge_body_move_to(@c_body, x, y, z)
    end
    
    def translate(dx,dy,dz)
      FFI::Sprite3D_C::bridge_body_translate(@c_body, dx, dy, dz)
    end
    # untested
    
    def rotate_x(angle)
      FFI::Sprite3D_C::bridge_body_rotate_x(@c_body, angle)
    end
    
    def rotate_y(angle)
      FFI::Sprite3D_C::bridge_body_rotate_y(@c_body, angle)
    end
    
    def rotate_z(angle)
      FFI::Sprite3D_C::bridge_body_rotate_z(@c_body, angle)
    end
    
    def reset_rotation
      FFI::Sprite3D_C::bridge_body_reset_rotation(@c_body)
    end
    # untested
  end



  ### SCENE :
  class Scene
    attr_reader :c_scene

    def initialize()
      @c_scene  = FFI::Sprite3D_C::bridge_new_scene()
    end

    def <<(element)
      FFI::Sprite3D_C::bridge_scene_push_element(@c_scene,element.c_body)
    end

    def print(indent)
      FFI::Sprite3D_C::bridge_print_scene(@c_scene,indent)
    end

    def element_count
      FFI::Sprite3D_C::bridge_scene_get_element_count(@c_scene)
    end

    def sprite_count
      FFI::Sprite3D_C::bridge_scene_get_sprite_count(@c_scene)
    end
  end



  ### CAMERA :
  class Camera
    attr_reader :c_camera

    def initialize(x,y,z,fx,fy,fz,ux,uy,uz)
      @c_camera = FFI::Sprite3D_C::bridge_new_camera(x, y, z, fx, fy, fz, ux, uy, uz)
    end

    def print
      FFI::Sprite3D_C::bridge_print_camera(@c_camera)
    end

    def move_to(x,y,z)
      FFI::Sprite3D_C::bridge_camera_move_to(@c_camera, x, y, z)
    end
    # unstested

    def translate(dx,dy,dz)
      FFI::Sprite3D_C::bridge_camera_translate(@c_camera, dx, dy, dz)
    end
    # unstested

    def rotate_x(angle)
      FFI::Sprite3D_C::bridge_camera_rotate_x(@c_camera, angle)
    end

    def rotate_y(angle)
      FFI::Sprite3D_C::bridge_camera_rotate_y(@c_camera, angle)
    end
    
    def rotate_z(angle)
      FFI::Sprite3D_C::bridge_camera_rotate_z(@c_camera, angle)
    end
    
    def move_forward(speed)
      FFI::Sprite3D_C::bridge_camera_move_forward(@c_camera, speed)
    end
    
    def move_right(speed)
      FFI::Sprite3D_C::bridge_camera_move_right(@c_camera, speed)
    end
    
    def move_up(speed)
      FFI::Sprite3D_C::bridge_camera_move_up(@c_camera, speed)
    end
    # unstested
  end



  ### RENDERER :
  class Renderer
    attr_reader :c_renderer

    def initialize(args,width,height,near,far,max_sprites)
      @c_renderer = FFI::Sprite3D_C::bridge_new_renderer(width, height, near, far, max_sprites)

      max_sprites.times do |i|
        args.outputs.static_sprites << Engine3D::RenderSprite.new(@c_renderer, max_sprites - i - 1)
      end
    end
    
    def render_scene(camera,scene)
      FFI::Sprite3D_C::bridge_render_scene( @c_renderer,
                                            camera.c_camera,
                                            scene.c_scene )
    end
    
    def print
      FFI::Sprite3D_C::bridge_print_renderer(@c_renderer)
    end
    
    def sorted_sprites
      FFI::Sprite3D_C::bridge_renderer_get_sorted_sprites(@c_renderer)
    end
    
    def sorted_sprites_count
      FFI::Sprite3D_C::bridge_renderer_get_sorted_sprites_count(@c_renderer)
    end
  end

  class RenderSprite
    attr_reader :index
    attr_sprite
  
    def initialize(c_renderer,index)
      @c_renderer = c_renderer
      @c_sprites  = FFI::Sprite3D_C::bridge_renderer_get_sorted_sprites(c_renderer)
      @index      = index
    end
  
    def sprite
      self
    end
  
    def draw_override(ffi_draw)
      ffi_draw.draw_sprite_3( FFI::Sprite3D_C::bridge_sprite_get_draw_x(@c_sprites[@index]),
                              FFI::Sprite3D_C::bridge_sprite_get_draw_y(@c_sprites[@index]),
                              FFI::Sprite3D_C::bridge_sprite_get_draw_w(@c_sprites[@index]),
                              FFI::Sprite3D_C::bridge_sprite_get_draw_h(@c_sprites[@index]),
                              'data/sprites/spheres_all.png',
                              0.0,  # angle !!! Make an accessor in the bridge
                              255, 255, 255, 255, 
                              false, false,
                              nil, nil, nil, nil,
                              0.0, 0.0,
                              FFI::Sprite3D_C::bridge_sprite_get_atlas_x(@c_sprites[@index]),
                              FFI::Sprite3D_C::bridge_sprite_get_atlas_y(@c_sprites[@index]),
                              FFI::Sprite3D_C::bridge_sprite_get_atlas_w(@c_sprites[@index]),
                              FFI::Sprite3D_C::bridge_sprite_get_atlas_h(@c_sprites[@index]) )
    end
  end
end
