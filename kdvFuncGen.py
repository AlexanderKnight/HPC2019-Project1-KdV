import numpy as np

def func(x):
    y=(np.sin(np.pi*x))
    return y

points = 100
x = np.linspace(0,2,points, endpoint=False)
y = func(x)
f = open("KdVInitData.dat", "w")
f.write("{0}\n".format(points))
f.write("{0}\n".format(2.0/(float(points))))
for i in range(points):
    f.write("{0}\n".format(y[i]))
    f.write("{0}\n".format(x[i]))
f.close
g = open("TestInitData.dat", "w")
for i in range(points):
    g.write("{0} {1}\n".format(x[i],y[i]))
g.close

