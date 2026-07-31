import numpy as np
a = np.array([1,2,3,4]).reshape(-1,1)
ones = np.ones_like(a @ a.T)
print(ones - (a @ a.T))