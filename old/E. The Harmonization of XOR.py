t = int(input())
for _ in range(t):
  S = set()
  n,k,x = map(int,input().split())
  for i in range(1,n+1):
    S.add(i)
  parts = []
  for i in range(1,n+1):
    if i == x:
      parts.append([i])
      S.remove(i)
      continue
    if i in S:
      if x ^ i in S:
        S.remove(x^i)
        S.remove(i)
        parts.append([i,x^i])
  if S:
    last = []
    sm = 0
    for i in S:
      last.append(i)
      sm ^= i
    if sm != x and sm != 0:
      print("NO")
      continue
    if sm == 0: 
      if parts:
        for a in last:
          parts[-1].append(a)
      else:
        print("NO")
        continue
    else:
      parts.append(last)
  if len(parts) < k:
    print("NO")
    continue
  if (k - len(parts)) % 2 != 0:
    print("NO")
    continue
  print("YES")
  for i in range(k-1):
    print(len(parts[i]), end=' ')
    for a in parts[i]:
      print(a, end=' ')
    print()
  last = []
  for i in range(k-1,len(parts)):
    for a in parts[i]:
      last.append(a)
  print(len(last), end=' ')
  for a in last:
    print(a, end=' ')
  print()



