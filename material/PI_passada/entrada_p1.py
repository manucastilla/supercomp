import numpy as np
import numpy.random
import sys


n = 10  # linha
m = 3  # coluna
V = np.random.random((n, m))
print(n, m)
for i in range(V.shape[0]):
    print(*V[i])
