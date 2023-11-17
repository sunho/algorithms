import sys
from collections import defaultdict
input = sys.stdin.readline

n, k, D = map(int, input().split())
students = []
for _ in range(n):
  m, d = map(int, input().split())
  students.append((d, list(map(int,input().split()))))

students = sorted(students)
r = 0
freq = {}
freq = defaultdict(lambda: 0, freq)
cur = 0
ans = 0
for l in range(n):
  while r < n and students[r][0] - students[l][0] <= D:
    for x in students[r][1]:
      freq[x] += 1
    cur += 1
    r += 1
  
  uni = 0
  inter = 0
  for _,cnt in freq.items():
    if cnt != 0:
      uni += 1
    if cnt == cur:
      inter += 1
  ans = max(ans, (uni-inter)*cur)

  for x in students[l][1]:
    freq[x] -= 1
  cur -= 1

print(ans)
