t = int(input())

for _ in range(t):
  n = int(input())
  A = list(map(int, input().split()))
  ans = []
  ok = True
  for i in range(n):
    if A[i] == 0:
      ans.append(0)
    else:
      cnt = 0
      for j in range(i, n):
        if A[j] == 0:
          break
        A[j] = 0
        if j == n-1:
          ok = False
        cnt += 1
      ans.append(cnt)
  ans = reversed(ans)
  if not ok:
    print("NO")
  else:
    print("YES")
    for a in ans:
      print(a, end=" ")
    print()