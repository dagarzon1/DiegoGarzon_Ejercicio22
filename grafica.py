import numpy as np
import matplotlib.pyplot as plt

data=np.loadtxt("datos.txt")
label=data[0,3];
plt.plot(data[:,0], data[:,2], label="initial", color='b')
plt.plot(data[:,0], data[:,1], label="t=% s"%label, color='r')
plt.legend()
plt.savefig("grafica.pdf")
