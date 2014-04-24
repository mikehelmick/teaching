#!/usr/bin/ruby

def gcd(a, b)
  return a if b == 0
  gcd(b, a % b)
end

a = ARGV[0].to_i
b = ARGV[1].to_i
puts "The GCD of #{a} and #{b} is #{gcd(a, b)}"
