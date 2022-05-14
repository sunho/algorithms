# receive input
N, X = input().split()
N = int(N)
X = int(X)
A = []
B = []
for i in range(N):
  a, b = input().split()
  A.append(int(a))
  B.append(int(b))

# solve
prev = [False] * (X+1)
prev[0] = True # Takahashi was initially at x = 0
for turn in range(N):
  current = [False] * (X+1)
  for x in range(X):
    if prev[x]: # if it was able to reach x in the previous turn
      if x + A[turn] <= X:
        current[x+A[turn]] = True # mark x + A[i] as possible
      if x + B[turn] <= X:
        current[x+B[turn]] = True # mark x + B[i] as possible
  prev = current

if prev[X]:
  print("Yes")
else:
  print("No")
