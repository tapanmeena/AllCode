import math
x = 0
y = 0
x1 = 0
y1 = 5
x2 = -5
y2 = -5
x3 = 5
y3 = 5
constant1 = 0.0005
constant2 = 0.0007

for i in range(20):
	a = ((x-x2)/math.sqrt((x-x2)*(x-x2) + (y-y2)*(y-y2))) - ((x-x1)/math.sqrt((x-x1)*(x-x1) + (y-y1)*(y-y1)))
	b = ((y-y2)/math.sqrt((x-x2)*(x-x2) + (y-y2)*(y-y2))) - ((y-y1)/math.sqrt((x-x1)*(x-x1) + (y-y1)*(y-y1)))
	c = ((x-x3)/math.sqrt((x-x3)*(x-x3) + (y-y3)*(y-y3))) - ((x-x1)/math.sqrt((x-x1)*(x-x1) + (y-y1)*(y-y1)))
	d = ((y-y3)/math.sqrt((x-x3)*(x-x3) + (y-y3)*(y-y3))) - ((y-y1)/math.sqrt((x-x1)*(x-x1) + (y-y1)*(y-y1)))

	temp = a
	a = d
	d = temp
	b = -1 * b
	c = -1 * c

	f = math.sqrt((x-x2)*(x-x2) + (y-y2) * (y-y2)) - math.sqrt((x-x1) * (x-x1) + (y-y1) * (y-y1) ) - constant1
	g = math.sqrt((x-x3)*(x-x3) + (y-y3) * (y-y3)) - math.sqrt((x-x1) * (x-x1) + (y-y1) * (y-y1) ) - constant2

	x = x - (d * f - b * g)
	y = y - (a * g - f * c)
	print("i ",i)
	print("x ",x)
	print("y ",y)