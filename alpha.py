import matplotlib as mpl
from matplotlib import rc
from matplotlib import gridspec
from mpl_toolkits.axes_grid1 import AxesGrid
from mpl_toolkits.axes_grid1 import make_axes_locatable
from matplotlib.transforms import blended_transform_factory

#mpl.rcParams['text.latex.preamble']=[r"\usepackage{amsmath}"]
#mpl.rcParams["text.usetex"] = True
#mpl.rcParams['font.family'] = 'sans-serif'
#mpl.rcParams['font.sans-serif'] = 'cm'
mpl.rcParams["lines.linewidth"] = 2.0
mpl.rcParams["axes.linewidth"] = 1.5
mpl.rcParams["axes.labelsize"] = 14.
mpl.rcParams["xtick.top"] = True
mpl.rcParams["xtick.labelsize"] = 14
mpl.rcParams["xtick.direction"] = "in"
mpl.rcParams["ytick.right"] = True
mpl.rcParams["ytick.labelsize"] = 14
mpl.rcParams["ytick.direction"] = "in"

import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt("zAlphaSR.txt")

for i in range(0,len(data[:,0])):
    if data[i,0] > 0.0:
        data[i,0] = -1.0*data[i,0]

# plt.hist(data[:,0],weights=data[:,3],bins=50)

plt.plot(data[:,0],data[:,2],color='black',label='Analytic')
# plt.scatter(data[:,0],data[:,3],label='Spherical Polar')
plt.scatter(data[0:150,0],data[0:150,3],label='Behind')
plt.scatter(data[151:-1,0],data[151:-1,3],label='Forward')
# plt.scatter(data[:,0]-0.5*1.3*1.0,data[:,3]/10.0,label='Mean')
# # plt.plot(data[:,0],data[:,3]/np.max(data[:,3]),color='red',label='Density')
plt.ylim(-0.1,50.1)

plt.xlabel(r"$s$")
plt.ylabel(r"$\alpha$")

plt.legend(loc='upper left')

plt.savefig("alphaSP.png",bbox_inches='tight')
