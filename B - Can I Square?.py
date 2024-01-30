import math
t = int(input())
for _ in range(t):
  n = int(input())
  A = list(map(int, input().split()))
  a = sum(A)
  if int(math.sqrt(a)) * int(math.sqrt(a)) == a:
    print("YES")
  else:
    print("NO")
