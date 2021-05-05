require 'lib/sprite3d_bridge.rb'
#require 'lib/constants3d.rb'
#require 'lib/vector3d.rb'
#require 'lib/matrix3d.rb'
#require 'lib/vertex3d.rb'
#require 'lib/body3d.rb'
#require 'lib/camera3d.rb'
#require 'lib/render3d.rb'
#require 'lib/sprite3d.rb'
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

  args.state.cube   = new_empty_body(8)
  cube_sprite_array = get_body_sprites(args.state.cube)
  sprites.each.with_index { |s,i| cube_sprite_array[i] = s }
  body_move_to(args.state.cube, 0.0, 0.0, -30.0)

  args.state.scene  = new_scene
  args.state.scene.scene_push_element args.state.scene, args.state.cube
  #print_scene args.state.scene, 0


  # Camera
  args.state.camera       = new_camera( 0.0, 0.0, 0.0,    # position
                                        0.0, 0.0,-1.0,    # forward
                                        0.0, 1.0, 0.0 )   # up
  #print_camera args.state.camera
  

  # Renderer :
  args.state.renderer     = new_renderer( 1280, 720,    # viewport size
                                          1.0, 300.0,   # near and far planes
                                          scene_get_sprite_count(args.state.scene) )

  #print_renderer  args.state.renderer


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
  #args.state.scene.bodies.each do |body|
  #  body.rotate_absolute( { :x => args.state.angle, :y => 2*args.state.angle, :z => 1.5*args.state.angle } )
  #  args.state.angle += 0.01
  #end
  body_rotate_x(args.state.cube,        args.state.angle)
  body_rotate_y(args.state.cube,  0.3 * args.state.angle)
  body_rotate_z(args.state.cube, 0.7 * args.state.angle)


  ## 2. RENDERING :

  # Backgound :
  args.outputs.solids << [0,   0, 1280, 306, 0, 0, 231]
  args.outputs.solids << [0, 306, 1280, 719, 180, 180, 231]

  # Sprites :
  renderer_scene  args.state.renderer,
                  args.state.camera,
                  args.state.scene

  if args.state.tick_count == 0 then
    args.state.sorted_sprites = renderer_get_sorted_sprites(args.state.renderer)
  end

  #puts 'Rendering frame... '
  7.downto(0) do |i|
    #puts "#{i} -> #{sprite_get_atlas_file(rendered_sprites[i])}"
    #puts "#{i} -> #{sprite_get_draw_x(rendered_sprites[i])}"
    args.outputs.sprites << { x:        sprite_get_draw_x(args.state.sorted_sprites[i]),
                              y:        sprite_get_draw_y(args.state.sorted_sprites[i]),
                              w:        sprite_get_draw_w(args.state.sorted_sprites[i]),
                              h:        sprite_get_draw_h(args.state.sorted_sprites[i]),
                              path:     'data/sprites/spheres_all.png',#sprite_get_atlas_file(rendered_sprites[i]),
                              source_x: sprite_get_atlas_x(args.state.sorted_sprites[i]),
                              source_y: sprite_get_atlas_y(args.state.sorted_sprites[i]),
                              source_w: sprite_get_atlas_w(args.state.sorted_sprites[i]),
                              source_h: sprite_get_atlas_h(args.state.sorted_sprites[i]) }
  end
  #puts 'Done!'

  # DEBUG :
  args.outputs.labels << [10, 700, "FPS: #{args.gtk.current_framerate.to_s.to_i}", 0, 0, 0, 255]
end
