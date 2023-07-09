t = int(input())
for _ in range(t):
  n, k = map(int, input().split())
  A = [0] * n
  for i in range(n):
    pre = 0
    suf = 0
    for j in range(i+1):
      pre += A[j]
    if pre < (i+k)//k:
      A[i] = 1
    for j in range(i+1):
      suf += A[n-j-1]
    if suf < (i+k)//k:
      A[n-i-1] = 1
  sum = 0
  for a in A:
    sum += a
  print(sum)
