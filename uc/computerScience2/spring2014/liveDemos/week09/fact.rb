#!/usr/bin/ruby

def fact(num)
  return 1 if (num <= 0)
  num * fact(num - 1)
end

num = ARGV[0].to_i;
0.upto(num) do |i|
  puts "fact(#{i}) = #{fact(i)}"
end

