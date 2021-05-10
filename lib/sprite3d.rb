class Sprite3D
  attr_reader :index
  attr_sprite

  #def initialize(c_sprites,index)
  def initialize(renderer,index)
    @renderer   = renderer
    @c_sprites  = renderer_get_sorted_sprites(renderer)
    @index      = index
    #puts "sprite index: #{@index} - renderer pointer: #{@renderer} - c_sprites:#{@c_sprites}"
  end

  def sprite
    self
  end

  def draw_override(ffi_draw)
    #puts "sprite index: #{@index} - renderer pointer: #{@renderer.value} - c_sprites:#{@c_sprites.value}"
    ffi_draw.draw_sprite_3( sprite_get_draw_x(@c_sprites[@index]),
                            sprite_get_draw_y(@c_sprites[@index]),
                            sprite_get_draw_w(@c_sprites[@index]),
                            sprite_get_draw_h(@c_sprites[@index]),
                            'data/sprites/spheres_all.png',
                            0.0,  # angle !!! Make an accessor in the bridge
                            255, 255, 255, 255, 
                            false, false,
                            nil, nil, nil, nil,
                            0.0, 0.0,
                            sprite_get_atlas_x(@c_sprites[@index]),
                            sprite_get_atlas_y(@c_sprites[@index]),
                            sprite_get_atlas_w(@c_sprites[@index]),
                            sprite_get_atlas_h(@c_sprites[@index]) )
  end
end

#module Engine3D
#  class Sprite3D < Vertex
#    attr_accessor :x, :y, :scale
#    
#    def initialize(x,y,z,atlas,atlas_x,atlas_y,atlas_w,atlas_h)
#      super(x,y,z)
#
#      @path     = atlas
#
#      @width    = atlas_w
#      @height   = atlas_h
#
#      @x        = -1280
#      @y        = -720
#      @w        = 16
#      @h        = 16
#      @angle    = 0
#      @r        = 255
#      @g        = 255
#      @b        = 255
#      @a        = 255
#      @source_x = atlas_x
#      @source_y = atlas_y
#      @source_w = atlas_w
#      @source_h = atlas_h
#
#      @scale    = 1
#    end
#
#    def set_scale(scale)
#      @scale    = scale
#      @width   *= scale
#      @height  *= scale
#    end
#
#    def sprite
#      self
#    end
#
#    def draw_override(ffi_draw)
#      draw_width  = (  @width / @view[2].abs ).to_i
#      draw_height = ( @height / @view[2].abs ).to_i 
#
#      if in_frustum then
#        ffi_draw.draw_sprite_3  @x - ( draw_width >> 1 ),
#                                @y - ( draw_height >> 1),
#                                draw_width,
#                                draw_height,
#                                @path,
#                                @angle,
#                                255, 255, 255, 255, 
#                                false, false,
#                                nil, nil, nil, nil,
#                                0.0, 0.0,
#                                @source_x, @source_y, @source_w, @source_h
#      end
#    end
#
#    def rotate(delta_angle)
#      @angle  = ( @angle + delta_angle ) % 360
#    end
#
#    def rotate_absolute(angle)
#      @angle  = angle
#    end
#
#    def z_scale(sprite_scale)
#      @w = ( sprite_scale *  @width / @view.z.abs ).to_i 
#      @h = ( sprite_scale * @height / @view.z.abs ).to_i 
#      @x -= @w / 2
#      @y -= @h / 2
#
#      self
#    end
#
#    def serialize
#      { path:   @path,
#        width:  @width,
#        height: @height }
#    end
#
#    def inspect
#      serialize.to_s
#    end
#
#    def to_s
#      serialize.to_s
#    end
#  end
#end
