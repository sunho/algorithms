t = int(input())
for _ in range(t):
  a, b = map(int, input().split())
  n, m = map(int, input().split())
  q = n // (m+1)
  r = n % (m+1)
  print(min(b*n, a*m*q + b*r, a*m*q + a*r))
