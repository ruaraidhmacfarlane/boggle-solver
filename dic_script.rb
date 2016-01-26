File.open('dictionary.txt', 'w') {|file| file.truncate(0) }

def pick_random_line
  chosen_line = nil
  File.foreach("Wordlist.txt").each_with_index do |line, number|
    chosen_line = line if rand < 1.0/(number+1)
  end
  return chosen_line
end

arr = []

10.times do
	i = pick_random_line
	while arr.include?(i)
		i = pick_random_line
	end
	arr << i
end

arr.sort!

File.open("dictionary.txt", "w+") do |f|
  arr.each { |element| f.puts(element) }
end