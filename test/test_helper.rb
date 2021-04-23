require           'minitest/pride'

require_relative  '../lib/constants3d.rb'
require_relative  '../lib/vector3d.rb'
require_relative  '../lib/matrix3d.rb'
require_relative  '../lib/vertex3d.rb'
require_relative  '../lib/sprite3d.rb'
require_relative  '../lib/body3d.rb'
require_relative  '../lib/camera3d.rb'
require_relative  '../lib/render3d.rb'
require_relative  '../lib/game3d.rb'

class Array
  alias_method :value, :[] 
end
