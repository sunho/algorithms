import sys
from collections import deque
input = sys.stdin.readline
n, q = map(int, input().split())
adj = [[] for _ in range(n)]
for _ in range(n-1):
  u, v, w = map(int, input().split())
  u-=1
  v-=1
  adj[u].append((v, w))
  adj[v].append((u,w))

for _ in range(q):
  k, v = map(int, input().split())
  v-=1
  queue = deque()
  queue.append(v)
  dist = [-1 for _ in range(n)]
  dist[v] = int(1e9)
  while queue:
    u = queue.popleft()
    for v, w in adj[u]:
      if dist[v] == -1:
        dist[v] = min(dist[u], w)
        queue.append(v)
  ans = 0
  for x in dist:
    if x >= k:
      ans += 1
  print(ans-1)
