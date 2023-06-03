import sys

sys.setrecursionlimit(int(1e3))
n = int(input())
points = []
for i in range(n):
  x,y = map(int,input().split())
  if x > y:
    x,y = y,x
  points.append((x,y))

dp = dict()

def inside(p, L, R):
  x,y = p
  if L[1] + L[0] - 2 >= 50:
    if x <= L[1] <= x+100 and x <= L[0]:
      return False
    if L[1] <= y+100 and y <= L[0]:
      return False
  else:
    if L[0] <= x and x <= L[1]:
      return False
    if L[0] <= y and y <= L[1]:
      return False
  if R != (0,0):
    if R[1] + R[0] - 2 >= 50:
      if not (R[1] < x+100 and x < R[0]):
        return False
      if not (R[1] < y+100 and y < R[0]):
        return False
    else:
      if not (R[0] < x and x < R[1]):
        return False
      if not (R[0] < y and y < R[1]):
        return False
  return True

def f(L, R):
  if (L,R) in dp:
    return dp[(L,R)]
  print((L,R))
  cands = []
  for i in range(n):
    x,y = points[i]
    if inside((x,y), L, R):
      cands.append(points[i])
      print("c:", points[i])
  res = 0
  print(len(cands))
  for x,y in cands:
    assert (x,y) != L
    assert (x,y) != R
    res = max(res, f(L, (x,y)) + f((x,y), R) + 1)
  dp[(L,R)]= res
  print("set", (L,R))
  return res
print(f((0,0), (0,0)))