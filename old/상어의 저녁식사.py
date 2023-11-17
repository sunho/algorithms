import sys
input = sys.stdin.readline

def main():
  n = int(input())
  A = [tuple(map(int,input().split())) for _ in range(n)]
  bm = bipariate_match(n, n)
  for i in range(n):
    for j in range(i+1,n):
      if all(A[i][z] >= A[j][z] for z in range(3)):
        bm.add(i,j)
      elif all(A[i][z] <= A[j][z] for z in range(3)):
        bm.add(j,i)
  print(n - bm.run())
  
class bipariate_match:
  def __init__(self, n, m):
    self.n = n
    self.m = m
    self.mt = [-1] * m
    self.adj = [[] for _ in range(n)]
  def add(self, u, v):
    self.adj[u].append(v)
  def run(self):
    def dfs(vis, u):
      if vis[u]:
        return False
      vis[u] = True
      for v in self.adj[u]:
        if self.mt[v] == -1 or dfs(vis, self.mt[v]):
          self.mt[v] = u
          return True
      return False
    matched = 0
    for i in range(self.n):
      vis = [False] * self.n
      if dfs(vis, i):
        matched += 1
      vis = [False] * self.n
      if dfs(vis, i):
        matched += 1
    return matched
main()
