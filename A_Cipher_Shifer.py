import sys
input = sys.stdin.readline
t = int(input())
for _ in range(t):
  n = int(input())
  s = input()
  ans = ""
  i = 0
  while i < n:
    cur = s[i]
    ans += cur
    i += 1
    while s[i] != cur:
      i += 1
    i += 1
  print(ans)