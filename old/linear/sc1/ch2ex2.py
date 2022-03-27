import numpy as np
from numpy import linalg as LA


x = np.array([2,-1,3,2]).reshape((-1,1))
y = np.array([3,2,1,-4]).reshape((-1,1))
print(LA.norm(x))
print(LA.norm(y))
print(LA.norm(x-y))