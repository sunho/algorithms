t = int(input())

for _ in range(t):
  n = int(input())
  A = list(map(int,input().split()))
  cnt = 0
  for a in A:
    if a == 1:
      cnt += 1
  print(cnt % 2 + (n - cnt) + cnt // 2)
