import sys
from collections import defaultdict
import heapq
input = sys.stdin.readline

n = int(input())
A = list(map(int, input().split()))

cnt = defaultdict(lambda: 0)

for i in range(n):
  cnt[A[i]] += 1
  A[i] *= -1

ans = 0
heapq.heapify(A)
while A:
  a = heapq.heappop(A)
  a *= -1
  if cnt[a] == 0:
    continue
  sz = 0
  for i in range(a,0,-1):
    if cnt[i] >= 1:
      cnt[i] -= 1
      sz += 1
    else:
      break
  ans += sz*a
print(ans)


