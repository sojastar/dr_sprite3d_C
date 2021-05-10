require 'lib/sprite3d_bridge.rb'
#require 'lib/constants3d.rb'
#require 'lib/vector3d.rb'
#require 'lib/matrix3d.rb'
#require 'lib/vertex3d.rb'
#require 'lib/body3d.rb'
#require 'lib/camera3d.rb'
#require 'lib/render3d.rb'
require 'lib/sprite3d.rb'
#require 'lib/scene3d.rb'





# ---=== CONSTANTS : ===---
SPRITE_SCALE  = 80 





# ---=== SETUP : ===---
def setup(args)
  # Scene :
  cube_sprites        = make_cube(18)
  args.state.cube     = new_empty_body(cube_sprites.length)
  cube_sprite_array   = get_body_sprites(args.state.cube)
  cube_sprites.each.with_index { |s,i| cube_sprite_array[i] = s }
  body_move_to(args.state.cube, 0.0, 0.0, -75.0)

  args.state.scene    = new_scene
  args.state.scene.scene_push_element args.state.scene, args.state.cube

  scene_sprite_count  = scene_get_sprite_count(args.state.scene)


  # Camera
  args.state.camera       = new_camera( 0.0, 0.0, 0.0,    # position
                                        0.0, 0.0,-1.0,    # forward
                                        0.0, 1.0, 0.0 )   # up
  

  # Renderer :
  args.state.renderer     = new_renderer( 1280, 720,    # viewport size
                                          1.0, 300.0,   # near and far planes
                                          scene_sprite_count )

  sorted_sprites          = renderer_get_sorted_sprites(args.state.renderer)

  scene_sprite_count.times do |i|
    args.outputs.static_sprites << Sprite3D.new(args.state.renderer, scene_sprite_count - i - 1)
  end


  # Miscellenaous :
  args.state.angle        = 0.03


  args.state.setup_done = true
  puts "Setup done!!!"
end





# ---=== MAIN LOOP : ===---
def tick(args)
  
  # SETUP :
  setup(args) unless args.state.setup_done


  # MAIN LOOP :
  
  # 1. GAME LOGIC :
  body_rotate_x(args.state.cube,       args.state.angle)
  body_rotate_y(args.state.cube, 0.3 * args.state.angle)
  body_rotate_z(args.state.cube, 0.7 * args.state.angle)


  ## 2. RENDERING :

  # Backgound :
  args.outputs.solids << [0,   0, 1280, 306,   0,   0, 231]
  args.outputs.solids << [0, 306, 1280, 719, 180, 180, 231]

  # Sprites :
  renderer_scene  args.state.renderer,
                  args.state.camera,
                  args.state.scene


  # DEBUG :
  args.outputs.labels << [10, 700, "FPS: #{args.gtk.current_framerate.to_s.to_i}", 0, 0, 0, 255]
end

def new_cube_sprite(x,y,z,color)
  color_offset  = case color
                  when :blue  then 0
                  when :green then 16
                  when :red   then 32
                  end

  new_sprite(x.to_f,y.to_f,z.to_f, 16, 16, 80, 'data/sprites/spheres_all.png', color_offset, 0, 16, 16)
end

def make_cube(size=10)
  cube_sprites = []

  # Blue balls :
  size.times do |i|
    size.times do |j|
      cube_sprites << new_cube_sprite(2*i - size + 1, 2*j - size + 1, -1.0 - size, :blue)
      cube_sprites << new_cube_sprite(2*i - size + 1, 2*j - size + 1,  1.0 + size, :blue)
    end
  end

  # Green balls :
  size.times do |i|
    size.times do |j|
      cube_sprites << new_cube_sprite(-1.0 - size, 2*i - size + 1, 2*j - size + 1, :green)
      cube_sprites << new_cube_sprite( 1.0 + size, 2*i - size + 1, 2*j - size + 1, :green)
    end
  end

  # Red balls :
  size.times do |i|
    size.times do |j|
      cube_sprites << new_cube_sprite( 2*i - size + 1, -1.0 - size, 2*j - size + 1, :red)
      cube_sprites << new_cube_sprite( 2*i - size + 1,  1.0 + size, 2*j - size + 1, :red)
    end
  end

  cube_sprites
end
