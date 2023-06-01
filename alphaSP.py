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

# plt.plot(data[:,0],data[:,1],color='black',label='Analytic')
plt.scatter(data[:,0],data[:,2],label='Spherical Polar')
plt.ylim(-0.001,0.051)

plt.xlabel(r"$s$")
plt.ylabel(r"$\alpha$")

plt.legend(loc='upper left')

plt.savefig("alphaSP.pdf",bbox_inches='tight')