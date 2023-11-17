t = int(input())
for _ in range(t):
  x, y = map(int, input().split())
  ans = []
  for a in range(x,y,-1):
    ans.append(a)
  for a in range(y,x):
    ans.append(a)
  print(len(ans))
  print(' '.join(map(str,ans)))
