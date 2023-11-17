def main():
  n, m, k = map(int, input().split())
  mt = bipariate_match(n,m)
  for i in range(n):
    works = list(map(int, input().split()))
    works = works[1:]
    works = [a - 1 for a in works]
    for j in works:
      mt.add(i,j)
  print(mt.run(k))

class bipariate_match:
  def __init__(self, n, m):
    self.n = n
    self.m = m
    self.mt = [-1] * m
    self.adj = [[] for i in range(n)]
  def add(self, u, v):
    self.adj[u].append(v)
  def run(self, k):
    matched = 0
    def dfs(vis, u):
      if vis[u]:
        return False
      vis[u] = True
      for v in self.adj[u]:
        if self.mt[v] == -1 or dfs(vis, self.mt[v]):
          self.mt[v] = u
          return True
      return False
    for i in range(self.n):
      vis = [False] * self.n
      if dfs(vis, i):
        matched += 1
    cnt = 0
    for i in range(self.n):
      vis = [False] * self.n
      if dfs(vis, i):
        matched += 1
        cnt += 1
      if cnt == k:
        break
    return matched

main()