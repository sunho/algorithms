import sys
input = sys.stdin.readline

X = input()
n = len(X)
cnt = 0
ans = ''
for i in range(n):
  if X[i] == 'X':
    cnt += 1
  elif X[i] == '.':
    if cnt % 2 != 0:
      print(-1)
      exit(0)
    ans += 'AAAA' * (cnt // 4)
    ans += 'BB' * ((cnt % 4) // 2)
    cnt = 0
    ans += '.'
if cnt % 2 != 0:
  print(-1)
  exit(0)
ans += 'AAAA' * (cnt // 4)
ans += 'BB' * ((cnt % 4) // 2)
print(ans)

