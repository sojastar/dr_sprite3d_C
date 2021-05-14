require 'lib/sprite3d_bridge.rb'





# ---=== SETUP : ===---
def setup(args)
  # Scene :
  cube_sprites          = make_cube(18)

  args.state.cube       = Engine3D::Body.new cube_sprites
  args.state.cube.move_to 0.0, 0.0, -75.0

  args.state.scene      = Engine3D::Scene.new
  args.state.scene << args.state.cube


  # Camera
  args.state.camera     = Engine3D::Camera.new  0.0, 0.0, 0.0,  # position
                                                0.0, 0.0,-1.0,  # forward
                                                0.0, 1.0, 0.0   # up
  

  # Renderer :
  args.state.renderer   =  Engine3D::Renderer.new args,
                                                  1280, 720,  # viewport size
                                                  1.0, 300.0, # near and far plans
                                                  args.state.scene.sprite_count,
                                                  ['data/sprites/spheres_all.png']


  # Miscellenaous :
  args.state.cube_rotation_speed      = 0.03
  args.state.camera_rotation_speed    = 0.01
  args.state.camera_translation_speed = 0.3

  args.state.setup_done = true
  puts "Setup done!!!"
end





# ---=== MAIN LOOP : ===---
def tick(args)
  
  # SETUP :
  setup(args) unless args.state.setup_done


  # MAIN LOOP :
  
  # 1. GAME LOGIC :
  
  # 1.1 Rotate the cube :
  args.state.cube.reset_rotation
  args.state.cube.rotate_x(       args.state.angle )
  args.state.cube.rotate_y( 0.3 * args.state.angle )
  args.state.cube.rotate_z( 0.7 * args.state.angle )
  args.state.angle += 0.03

  # 1.2 Moving the camera :

  # Rotation :
  args.state.camera.rotate_z( args.state.camera_rotation_speed) if args.inputs.keyboard.key_held.q
  args.state.camera.rotate_z(-args.state.camera_rotation_speed) if args.inputs.keyboard.key_held.e
  args.state.camera.rotate_x( args.state.camera_rotation_speed) if args.inputs.keyboard.key_held.w
  args.state.camera.rotate_x(-args.state.camera_rotation_speed) if args.inputs.keyboard.key_held.s
  args.state.camera.rotate_y( args.state.camera_rotation_speed) if args.inputs.keyboard.key_held.a
  args.state.camera.rotate_y(-args.state.camera_rotation_speed) if args.inputs.keyboard.key_held.d

  # Translation :
  args.state.camera.move_forward(-args.state.camera_translation_speed) if args.inputs.keyboard.key_held.up
  args.state.camera.move_forward( args.state.camera_translation_speed) if args.inputs.keyboard.key_held.down
  args.state.camera.move_right(-args.state.camera_translation_speed) if args.inputs.keyboard.key_held.left
  args.state.camera.move_right( args.state.camera_translation_speed) if args.inputs.keyboard.key_held.right


  ## 2. RENDERING :

  # Backgound :
  args.outputs.solids << [0,   0, 1280, 306,   0,   0, 231]
  args.outputs.solids << [0, 306, 1280, 719, 180, 180, 231]

  # Sprites :
  args.state.renderer.render_scene  args.state.camera,
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

  Engine3D::new_sprite(x.to_f,y.to_f,z.to_f, 16, 16, 80, 0, color_offset, 0, 16, 16)
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
