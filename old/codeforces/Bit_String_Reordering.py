from collections import deque


n, m = map(int, input().split())
A = list(input().split())
B = list(map(int, input().split()))
def build(B, s):
  res = ""
  for b in B:
    res += s*b
    s = "1" if s == "0" else "0"
  return int(res, base=2)
def bswap(n, i, j):
  a = bool(n & (1<<i))
  b = bool(n & (1<<j))
  return n ^ (a << i) ^ (b << j) ^ (b << i) ^ (a << j)
a = int("".join(A), base=2)
dest1 = build(B,"0")
dest2 = build(B,"1")
N = 15
inf = 10**9
dist = [inf] * (1<<N)
q = deque()
q.append(a)
dist[a] = 0
while q:
  u = q.popleft()
  for i in range(N-1):
    v = bswap(u,i,i+1)
    if dist[v] == inf:
      dist[v] = dist[u] + 1
      q.append(v)
print(min(dist[dest1], dist[dest2]))