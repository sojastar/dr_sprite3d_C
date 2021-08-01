$gtk.ffi_misc.gtk_dlopen("sprite3d")

module Engine3D
  ### VERTICES :
  class Vertex
    attr_reader :c_vertex

    def initialize(x,y,z)
      @c_vertex = FFI::Sprite3D_C::bridge_new_vertex(x, y, z)
    end

    def vertex_reset
      FFI::Sprite3D_C::bridge_vertex_reset(@c_vertex)
    end

    def set_local_coordinates(x,y,z)
      FFI::Sprite3D_C::bridge_vertex_set_local_coordinates(@c_vertex, x, y, z)

    def compute_world_coordinates(body);
      FFI::Sprite3D_C::bridge_vertex_compute_world_coordinates(@c_vertex, body)
    end

    def compute_view_coordinates(camera)
      FFI::Sprite3D_C::bridge_vertex_compute_view_coordinates(@c_vertex, camera)
    end

    def get_local_coordinates
      FFI::Sprite3D_C::bridge_vertex_get_local_coordinates(@c_vertex) 
    end

    def get_world_coordinates
      FFI::Sprite3D_C::bridge_vertex_get_world_coordinates(@c_vertex) 
    end

    def get_view_coordinates
      FFI::Sprite3D_C::bridge_vertex_get_view_coordinates(@c_vertex) 
    end
  end


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
    attr_reader :c_renderer,
                :atlases

    #def initialize(args,width,height,near,far,max_sprites)
    def initialize(args,width,height,near,far,max_sprites,atlases)
      @c_renderer = FFI::Sprite3D_C::bridge_new_renderer(width, height, near, far, max_sprites)

      @atlases    = atlases

      max_sprites.times do |i|
        args.outputs.static_sprites << Engine3D::RenderSprite.new(self, max_sprites - i - 1)
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
    WIDTH             = 0
    HEIGHT            = 1
    SCALE             = 2
    DRAW_X            = 3
    DRAW_Y            = 4
    DRAW_WIDTH        = 5
    DRAW_HEIGHT       = 6
    ANGLE             = 7
    ATLAS_FILE_INDEX  = 8
    ATLAS_X           = 9
    ATLAS_Y           = 10
    ATLAS_W           = 11
    ATLAS_H           = 12

    attr_reader :index
    attr_sprite
  
    def initialize(renderer,index)
      @atlases    = renderer.atlases
      @c_sprites  = FFI::Sprite3D_C::bridge_renderer_get_sorted_sprites(renderer.c_renderer)
      @index      = index
    end
  
    def sprite
      self
    end
  
    def draw_override(ffi_draw)
      render_data = FFI::Sprite3D_C::bridge_sprite_get_render_data(@c_sprites[@index])
      ffi_draw.draw_sprite_3( render_data[DRAW_X],
                              render_data[DRAW_Y],
                              render_data[DRAW_WIDTH],
                              render_data[DRAW_HEIGHT],
                              @atlases[render_data[ATLAS_FILE_INDEX]],
                              render_data[ANGLE],
                              255, 255, 255, 255,
                              false, false,
                              nil, nil, nil, nil,
                              0.0, 0.0,
                              render_data[ATLAS_X],
                              render_data[ATLAS_Y],
                              render_data[ATLAS_W],
                              render_data[ATLAS_H] )
    end
  end
end
