def fibonacci( n, call )
  1.upto(call) { |x| print "  " }
  print "Calculating fibonacci of #{n}\n"
  if n < 3
    1
  else
    fibonacci( n - 1, call + 1 ) + fibonacci( n - 2, call + 1 )
  end
end

def better_fib( fib_cur, fib_prev, n )
  puts "#{fib_cur},#{fib_prev} n=#{n}"
  return fib_cur if n == 1
  better_fib( fib_cur + fib_prev, fib_cur, n - 1 )
end

def fib_seq( n )
  better_fib( 1, 0, n )
end

puts fibonacci( 10, 1 )
#puts fib_seq( 10 )
