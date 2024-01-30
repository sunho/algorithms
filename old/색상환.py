n = int(input())
k = int(input())

MOD = 1000000003 

def choose(n,k):
  if n < k:
    return 0
  if k < 0:
    return 0
  res = 1
  cur = 2
  for i in reversed(range(n-k+1,n+1)):
    res *= i
    if cur <= k and res % cur == 0:
      res //= cur
      cur += 1
  if cur <= k and res % cur == 0:
    res //= cur
    cur += 1
  return res % MOD

print((choose(n-k+1,k)-choose(n-k-1,k-2)+MOD)%MOD)
