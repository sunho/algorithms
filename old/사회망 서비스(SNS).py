""" For heavy recursion
"""
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
  
n = int(input())
adj = [[] for _ in range(n)]
for i in range(n-1):
  u,v = map(int,input().split())
  u-=1;v-=1
  adj[u].append(v)
  adj[v].append(u)

dp = [[0]*2 for _ in range(n)]

@bootstrap
def dfs(u, p, color):
  dp[u][0] = 0
  dp[u][1] = 1
  for v in adj[u]:
    if v == p:
      continue
    yield dfs(v, u, color ^ 1)
    dp[u][1] += min(dp[v][0],dp[v][1])
    dp[u][0] += dp[v][1]
  yield

dfs(0, -1, 0)

print(min(dp[0][0], dp[0][1]))

