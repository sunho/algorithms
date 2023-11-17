t = int(input())
for _ in range(t):
  n = int(input())
  s = input()
  done = dict()
  ans = 0
  for c in s:
    if c not in done:
      ans += 2
      done[c] = True
    else:
      ans += 1
  print(ans)
      

