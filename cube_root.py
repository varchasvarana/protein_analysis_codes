"""
this code will calculate the cube root of the number using newtons method
"""
x = 8
def myroot(x):
	ig = 1.0 #initial guess
	mi = 100 #max iterations
	for i in range(mi):
		ig = (2*ig + (x/(ig**2)))/3
	print(ig)
