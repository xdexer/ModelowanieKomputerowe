import numpy as np
import matplotlib.pyplot as plt

k_tab = np.linspace(2.4, 4.0, 10000)
N = 500
x = 0.5 + np.zeros(N)

endcap = np.arange(round(N * 0.9), N)

for ki in range(len(k_tab)):
    
    for n in range(N-1):
        x[n+1] = k_tab[ki] * x[n] * (1 - x[n])
    
    u = np.unique(x[endcap])
    k = k_tab[ki]*np.ones(len(u))
    plt.plot(k, u, 'k.', markersize=1)    

plt.show()