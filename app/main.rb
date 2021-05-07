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
  sprites = [ new_sprite(-1.0,-1.0,-1.0, 16, 16, 80, 'data/sprites/spheres_all.png',  0, 0, 16, 16),
              new_sprite( 1.0,-1.0,-1.0, 16, 16, 80, 'data/sprites/spheres_all.png', 16, 0, 16, 16),
              new_sprite( 1.0, 1.0,-1.0, 16, 16, 80, 'data/sprites/spheres_all.png', 32, 0, 16, 16),
              new_sprite(-1.0, 1.0,-1.0, 16, 16, 80, 'data/sprites/spheres_all.png', 48, 0, 16, 16),
              new_sprite(-1.0,-1.0, 1.0, 16, 16, 80, 'data/sprites/spheres_all.png',  0, 0, 16, 16),
              new_sprite( 1.0,-1.0, 1.0, 16, 16, 80, 'data/sprites/spheres_all.png',  0, 0, 16, 16),
              new_sprite( 1.0, 1.0, 1.0, 16, 16, 80, 'data/sprites/spheres_all.png',  0, 0, 16, 16),
              new_sprite(-1.0, 1.0, 1.0, 16, 16, 80, 'data/sprites/spheres_all.png',  0, 0, 16, 16) ]

  args.state.cube     = new_empty_body(8)
  cube_sprite_array   = get_body_sprites(args.state.cube)
  sprites.each.with_index { |s,i| cube_sprite_array[i] = s }
  body_move_to(args.state.cube, 0.0, 0.0, -30.0)

  args.state.scene    = new_scene
  args.state.scene.scene_push_element args.state.scene, args.state.cube
  #print_scene args.state.scene, 0

  scene_sprite_count  = scene_get_sprite_count(args.state.scene)


  # Camera
  args.state.camera       = new_camera( 0.0, 0.0, 0.0,    # position
                                        0.0, 0.0,-1.0,    # forward
                                        0.0, 1.0, 0.0 )   # up
  #print_camera args.state.camera
  

  # Renderer :
  args.state.renderer     = new_renderer( 1280, 720,    # viewport size
                                          1.0, 300.0,   # near and far planes
                                          scene_sprite_count )
  #print_renderer  args.state.renderer

  sorted_sprites          = renderer_get_sorted_sprites(args.state.renderer)

  scene_sprite_count.times do |i|
    args.outputs.static_sprites << Sprite3D.new(sorted_sprites, scene_sprite_count - i - 1)
  end


  # Miscellenaous :
  args.state.angle        = 0.05


  args.state.setup_done = true
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
  print 'C side render... '
  renderer_scene  args.state.renderer,
                  args.state.camera,
                  args.state.scene
  puts 'Done!!!'


  # DEBUG :
  args.outputs.labels << [10, 700, "FPS: #{args.gtk.current_framerate.to_s.to_i}", 0, 0, 0, 255]
end
