U = [0] * 20
U[0] = 1
U[3] = 1
U[4] = 1
U[5] = 1
U[6] = 1

for i in range(7,20):
  U[i] = U[i-3] + U[i-4] - U[i-7]

print(U[12])
