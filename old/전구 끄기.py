import sys
input = sys.stdin.readline

n = int(input())
A = [list(map(int,input().split())) for _ in range(n)]

N = 1 << n
inf = int(1e9)
ans = inf
for row in range(0,N):
  B = [[A[i][j] for j in range(n)] for i in range(n)]
  cnt = 0
  def flip(i, j):
    global cnt
    global B
    if i - 1 >= 0:
      B[i-1][j] ^= 1
    if j-1 >= 0:
      B[i][j-1] ^= 1
    B[i][j] ^= 1
    if j+1 < n:
      B[i][j+1] ^= 1
    if i+1 < n:
      B[i+1][j] ^= 1
    cnt += 1
  for i in range(n):
    if (row >> i) & 1:
      flip(0,i)
  for i in range(n-1):
    for j in range(n):
      if B[i][j] == 1:
        flip(i+1,j)
  if not any([any(val) for val in B]):
    ans = min(ans, cnt)

if ans == inf:
  print(-1)
else:
  print(ans)
