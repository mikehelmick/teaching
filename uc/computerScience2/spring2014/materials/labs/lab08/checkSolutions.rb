
fName = ARGV[0]

def isBoardLine(line) 
  idx1 = line.index('_')
  return false if idx1.nil?
  idx2 = line.index('_', idx1)
  return false if idx2.nil?
  # ok - probably a board line
  true
end

file = File.new(fName, "r")
while (line = file.gets)
  
  if (isBoardLine(line))
    board = line;
    # read 7 more lines
    1.upto(7) do |i| 
      line = file.gets
      board = board + line
    end
    flatBoard = ""
    board.each_char do |c|
      if c == '_' || c == 'Q'
        flatBoard = flatBoard + c
      end
    end
    puts flatBoard
  end
  
end
file.close