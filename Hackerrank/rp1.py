import math

class Points():
	def __init__(self, x, y, z):
		self.x = x
		self.y = y
		self.z = z

	def dotProduct(self, vec):
		return (self.x * vec.x ) + (self.y * vec.y ) + (self.z * vec.z )

	def crossProduct(self, vec):
		return Points((self.y * vec.z - self.z * vec.y), (self.z * vec.x - self.x * vec.z), (self.x * vec.y - self.y * vec.x))

	def __sub__(self, vec):
		return Points( (self.x - vec.x) , (self.y - vec.y) , (self.z - vec.z))

	def absolute(self):
		return pow((self.x ** 2 + self.y ** 2 + self.z ** 2), 0.5)

if __name__ == '__main__':
	A = Points(*map(float, input().split()))
	B = Points(*map(float, input().split()))
	C = Points(*map(float, input().split()))
	D = Points(*map(float, input().split()))

	X = (B - A).crossProduct(C - B)
	Y = (C - B).crossProduct(D - C)
	# print(X.absolute(), Y.absolute())
	phi = X.dotProduct(Y) / (X.absolute() * Y.absolute())

	result = math.degrees(math.acos(phi))	

	print("{:0.2f}".format(result))
	# print(str(round(result,2)))