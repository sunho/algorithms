h,w = map(int, input().split())

A = [input() for i in range(h)]
B = [input() for i in range(h)]
for s in range(h):
  for t in range(w):
    ok = True
    for i in range(h):
      for j in range(w):
        if A[(i+s)%h][(j+t)%w] != B[i][j]:
          ok = False
    if ok:
      print("Yes")
      exit(0)

print("No")