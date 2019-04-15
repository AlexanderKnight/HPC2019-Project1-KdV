import numpy as np

def func(x):
    y=(np.sin(np.pi*x))
    return y

def compfunc(x):
    y = 1./(np.cosh(x-10))**2
    return y

# Change values here to create different resolutions
# and change the domain. 
points = 100
startVal = 0
endVal = 20
initDataFileName = "KdVInitData.dat"

x = np.linspace(startVal,endVal,points, endpoint=False)
y = compfunc(x)
f = open(initDataFileName, "w")
f.write("{0}\n".format(points))
f.write("{0}\n".format(float(endVal-startVal)/(float(points))))
for i in range(points):
    f.write("{0}\n".format(y[i]))
    f.write("{0}\n".format(x[i]))
f.close
