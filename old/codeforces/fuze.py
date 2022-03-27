import random
import sys
N=1000
M=100
Q=1000
with open('input.txt', 'w') as f:
    sys.stdout = f 
    print(str(N))
    for i in range(N):
        d = {}
        print(str(M) + " 10")
        for j in range(M):
            p = tuple(random.randint(1, 100) for j in range(2))
            while p in d:
                p = tuple(random.randint(1, 100) for j in range(2))
            d[p] = 1
            print(str(p[0]) + ' ' + str(p[1]) + ' ' + str(random.randint(1, 100)))
