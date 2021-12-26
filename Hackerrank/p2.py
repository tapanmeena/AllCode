happiness  = 0
n, m = input().split()
l = set(input().split())
A = set(input().split())
B = set(input().split())

for i in l:
	if i in A:
		happiness += 1
	elif i in B:
		happiness -= 1

print (happiness)
# print (n,m)