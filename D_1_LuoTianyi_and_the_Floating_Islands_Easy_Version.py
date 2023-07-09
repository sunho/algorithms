def main():
  mod = int(1e9) + 7

  n, k = map(int, input().split())
  adj = [[] for i in range(n)]

  for i in range(n-1):
    u, v = map(int, input().split())
    u -= 1; v -= 1
    adj[u].append(v)
    adj[v].append(u)

  facts = [0] * (n+1)
  facts[0] = 1
  for i in range(1, n+1):
    facts[i] = facts[i-1]*i % mod
  invs = [0] * (n+1)
  for i in range(0, n+1):
    invs[i] = pow(facts[i], -1, mod)

  def choose(n, k):
    return (facts[n]*invs[n-k] % mod)*invs[k] % mod

  cnt = [0] * n
  @bootstrap
  def dfs(u, p):
    cnt[u] = 1
    for v in adj[u]:
      if v == p:
        continue
      cnt[u] += yield dfs(v, u)
    yield cnt[u]
  dfs(0, -1)

  total = choose(n, k)

  if k%2 == 0:
    for u in range(n):
      if cnt[u] >= k//2 and n-cnt[u] >= k//2:
        total += choose(cnt[u], k//2)*choose(n-cnt[u], k//2) % mod
        total %= mod

  ans = total * pow(choose(n, k), -1, mod) % mod
  print(ans)

import sys
input = sys.stdin.readline

from types import GeneratorType
def bootstrap(f, stack=[]):
  def wrappedfunc(*args, **kwargs):
    if stack:
      return f(*args, **kwargs)
    else:
      to = f(*args, **kwargs)
      while True:
        if type(to) is GeneratorType:
          stack.append(to)
          to = next(to)
        else:
          stack.pop()
          if not stack:
            break
          to = stack[-1].send(to)
      return to
  return wrappedfunc

main()