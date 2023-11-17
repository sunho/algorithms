MOD = int(1e9) + 7
N = 200000
facts = [1] * (N+1)
for i in range(1, N+1):
  facts[i] = i*facts[i-1] % MOD

def choose(n, k):
  if n < k:
    return 0
  if k < 0:
    return 0
  return facts[n] * pow(facts[n-k],-1,MOD) * pow(facts[k],-1,MOD)

n, m = map(int, input().split())

ans = 0
for i in range(1,m+1):
  ans += (m-i+1)*choose(i+n-2,n-1) % MOD
  ans %= MOD

for i in range(0,max(n,m)):
  ans += choose(m-n*i,n) % MOD;
  ans %= MOD

print(ans)
