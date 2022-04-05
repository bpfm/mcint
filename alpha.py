import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt("zAlpha.txt")

plt.scatter(data[:,0],data[:,1]/np.max(data[:,1]))
plt.plot(data[:,0],data[:,2]/np.max(data[:,2]),color='black')
plt.plot(data[:,0],data[:,3]/np.max(data[:,3]),color='red')
# plt.ylim(0.0,0.3)

plt.savefig("alpha.png")
