n = int(input())
A = list(map(int,input().split()))


MOD = 1000007

ans = 1
dp = [1 for _ in range(n+1)]
pf = [0 for _ in range(n+1)]
for i in range(n):
  pf[i+1] = max(pf[i], A[i])
for i in reversed(range(n)):
  ans += (A[i] - 1)*dp[pf[i]]
  ans %= MOD
  nxt = [0 for _ in range(n+1)]
  for j in range(n+1):
    if j + 1 <= n:
      nxt[j] += dp[j+1]
    nxt[j] += dp[j]*j
    nxt[j] %= MOD
  dp = nxt
print(ans)

