S1 = "zasxcdfvgbhnjmklpoyuitrewq"
S2 = "cba"
current_pointer = 0
time = 0
for char in S2:
	next_pointer = S1.find(char)
	time += abs(current_pointer-next_pointer)
	current_pointer = next_pointer
print(time)