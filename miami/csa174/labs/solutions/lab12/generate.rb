i = 30
j = 25

puts i
puts j

1.upto(i) do |student|
  outline = ""
  1.upto(j) do |test|
    outline = "#{outline}#{sprintf("%.2f", rand() *100)} "
  end
  puts outline
end