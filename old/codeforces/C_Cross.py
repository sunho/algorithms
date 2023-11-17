h, w = map(int, input().split())
A = [input() for i in range(h)]

def dfs(i, j, sz):
  if i-sz < 0 or i+sz >= h or j-sz < 0 or j+sz >= w:
    return 0
  if A[i-sz][j-sz] != '#' or A[i-sz][j+sz] != '#' or A[i+sz][j-sz] != '#' or A[i+sz][j+sz] != '#':
    return 0
  return dfs(i,j,sz+1)+1
ans = [0]*min(h,w)
for i in range(h):
  for j in range(w):
    sz = dfs(i,j,0) 
    if sz >= 2:
      ans[sz-2] += 1

for a in ans:
  print(a, end = ' ')