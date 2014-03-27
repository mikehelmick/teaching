class Maze
  
  SIZE = 9
  
  def initialize
    ## set up the array
    @x = Array.new(SIZE+1)
    0.upto(SIZE) {|x| @x[x] = Array.new(SIZE) }
    
    0.upto(SIZE) do |i|
      0.upto(SIZE) do |j|
        @x[i][j] = "W"  
      end
    end
    
    @pos = [0,0]
    set_path
    
    while( @pos[0] != SIZE && @pos[1] != SIZE )
      next_pos = relative_pos rand(4)
      while !valid_pos(next_pos)
        next_pos = relative_pos rand(4)
      end
      
      @pos = next_pos
      set_path
    end
    
  end
  
  def to_s
    str = ""
    @x.each do |arr|
      arr.each { |e| str += " #{e}" }
      str += "\n"
    end
    str
  end
  
  def valid_pos(pos)
    pos[0] >= 0 && pos[0] <= SIZE && pos[1] >= 0 && pos[1] <= SIZE
  end
  
  def relative_pos(dir)
    #puts "Direction #{dir}"
    return [@pos[0],@pos[1]-1] if dir == 0
    return [@pos[0]+1,@pos[1]] if dir == 1
    return [@pos[0],@pos[1]+1] if dir == 2
    return [@pos[0]-1,@pos[1]]    
  end
  
  def set_path
    @x[@pos[0]][@pos[1]] = "P"
  end
  
  
  private :set_path, :relative_pos, :valid_pos
end


maze = Maze.new
puts maze