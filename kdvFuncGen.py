import numpy as np

def func(x):
    y=np.cos(np.pi*x+1)
    return y

points = 10000
x = np.linspace(0,2,points, endpoint=False)
y = func(x)
f = open("KdVInitData.dat", "w")
f.write("{0}\n".format(points))
f.write("{0}\n".format(2.0/(float(points))))
for i in range(points):
    f.write("{0}\n".format(y[i]))
    f.write("{0}\n".format(x[i]))
f.close

