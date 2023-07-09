t = int(input())
def solve():
  n = int(input())
  A = list(map(int, input().split()))
  A = sorted(A)
  if A[0] < 0:
    print(A[0])
  else:
    print(A[-1])

for _ in range(t):
  solve()


# 2 7 9
# -10 -9 1 11
# 8 16 8 0 8 16 8