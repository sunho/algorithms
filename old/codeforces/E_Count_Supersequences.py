mod = int(1e9) + 7

t = int(input())
for _ in range(t):
  n, m, k = map(int, input().split())
  A = list(map(int, input().split()))
  invs = [0]*(n+1)
  ifacts = [0]*(n+1)
  facts = [0]*(n+1)
  ifacts[0] = 1
  facts[0] = 1
  for i in range(1,n+1):
    facts[i] = i * facts[i-1] % mod
  for i in range(1,n+1):
    ifacts[i] = (m-i+1) * ifacts[i-1] % mod
  for i in range(0,n+1):
    invs[i] = pow(facts[i], -1, mod)
  def choose(k):
    return ifacts[k]*invs[k]%mod
  ans = pow(k,m,mod)
  for i in range(n):
    ans = (ans - choose(i)*pow(k-1,m-i,mod) + mod) % mod
  print(ans)