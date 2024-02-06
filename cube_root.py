"""
this code will calculate the cube root of the number using newtons method
"""
def myroot(x):
	ig = 1.0 #initial guess
	mi = 100 #max iterations
	tol = 1.0e-15
	for i in range(mi):
		ig0 = ig
		ig = (2*ig + (x/(ig**2)))/3
		print(f"the value of root at iteration {i} is {ig:10.34f}")
		delta = ig-ig0
		if abs(delta)/x<tol:
			break
	       
		
	print(ig)
