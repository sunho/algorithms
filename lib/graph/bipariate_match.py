class bipariate_match:
  def __init__(self, n, m):
    self.n = n
    self.m = m
    self.mt = [-1] * m
    self.adj = [[] for i in range(n)]
  def add(self, u, v):
    self.adj[u].append(v)
  def run(self):
    used = [False] * self.n
    for i in range(self.n):
      for v in self.adj[i]:
        if self.mt[v] == -1:
          self.mt[v] = i
          used[i] = True
          break
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
      # add mt[i] == -1 check if arbitrary
      if used[i]:
        continue
      vis = [False] * self.n
      dfs(vis, i)