import functools
n, k = map(int, input().split())
A = []
for i in range(n):
  A.append(input())

def compare(l, r):
  for i in range(min(len(l), len(r))):
    if l[i] < r[i]:
      return 1
    elif l[i] > r[i]:
      return -1
  if len(l) == len(r):
    return 0
  if len(l) > len(r):
    if l[len(r)] == '0':
      return 1
    else:
      return -1
  else:
    if r[len(l)] == '0':
      return -1
    else:
      return 1

A.sort(key=functools.cmp_to_key(compare))
B = [int(x) for x in A]
mx = str(max(B))
rem = k-n
for i in range(n):
  print(A[i], end='')
  if mx == A[i]:
    print(A[i]*rem, end='')
    rem = 0
