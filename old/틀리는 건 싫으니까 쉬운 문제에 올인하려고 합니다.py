import sys
import heapq
input = sys.stdin.readline

n, m = map(int, input().split())

A = []

for i in range(n):
  d, p, t, e = map(int,input().split())
  if e == 1:
    d = (d + 1) // 2
    p //= 2
  A.append((d,p,t))

hp, dp = map(int, input().split())

A.sort()

cur = 0
done = 0
pq = []
ans = 0
while done < m:
  while cur < n and A[cur][0] <= hp:
    _,p,t = A[cur]
    heapq.heappush(pq, (-1*t, p))
    cur += 1
  if not pq:
    break
  t, p = heapq.heappop(pq)
  t *= -1
  if not t:
    ans += max(0,p-dp)
  hp += 1
  dp += 1
  done += 1

if done != m:
  print(-1)
else:
  print(ans)
