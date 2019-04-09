import numpy as np

"""
data = np.genfromtxt('0006.dat',
                     skip_header=0,
                     skip_footer=0,
                     names=True,
                     #usecols=(0),
                     delimiter="/t")

                    """


file_data = np.genfromtxt("0006.dat", usecols=(0,1), skip_header=1, dtype=float)
print(file_data)
x = file_data[:,0]
print(x)

y = file_data[:,1]
print(y)
