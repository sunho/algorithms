from sys import stdout
n = int(input())
A = list(map(int, input().split()))
S = sum(A)
N = S//2
dp = [0] * (N+1)
prd = [-1] * (N+1)
sel = [0] * (N+1)
dp[0] = 1
for i in range(n):
  for j in reversed(range(N+1)):
    if j - A[i] >= 0 and dp[j-A[i]] and not dp[j]:
      dp[j] = 1
      prd[j] = j - A[i]
      sel[j] = i

def query():
  return int(input())-1

def select(i):
  print(i+1)
  stdout.flush()


left = set()
right = set()

def process(i, j):
  d = min(A[i],A[j])
  A[i] -= d
  A[j] -= d
  if A[i] == 0:
    left.discard(i)
    right.discard(i)
  if A[j] == 0:
    left.discard(j)
    right.discard(j)

if S % 2 == 1 or not dp[N]:
  for i in range(n):
    left.add(i)
  print("First")
  while True:
    i = next(iter(left))
    select(i)
    if len(left) == 1:
      break
    j = query()
    process(i,j)
else:
  v = N
  while v != 0:
    left.add(sel[v])
    v = prd[v]
  for i in range(n):
    if i not in left:
      right.add(i)
  print("Second")
  while len(left) != 0 or len(right) != 0:
    i = query()
    if i in left:
      j = next(iter(right))
    else:
      j = next(iter(left))
    select(j)
    process(i,j)
