n, a, b = map(int, input().split())
C = list(map(int, input().split()))

for i in range(n):
  if a + b == C[i]:
    print(i+1)

