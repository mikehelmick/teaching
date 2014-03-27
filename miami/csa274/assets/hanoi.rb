class Tower
  
  # resursive method for solving the tower of hanoi
  # n is the number of disks
  def Tower.show_moves( n, start_peg, dest_peg, temp_peg )
    if n == 1 
      "Move disk 1 from peg #{start_peg} to peg #{dest_peg}\n"
    else
      result = show_moves( n - 1, start_peg, temp_peg, dest_peg )
      result = result + "Move disk #{n} from peg #{start_peg} to peg #{dest_peg}\n"
      result + show_moves( n - 1, temp_peg, dest_peg, start_peg ) 
    end
  end
  
end


puts Tower.show_moves( 5, "L", "M", "R" )