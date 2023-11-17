import sys
input = sys.stdin.readline
n = int(input())
A = [int(input()) for i in range(n)]

stk = []
ans = 0
for i in range(n):
  if not stk:
    stk.append((A[i], i))
  else:
    cur = i
    while stk and stk[-1][0] > A[i]:
      cur = stk[-1][1]
      ans = max(ans, stk[-1][0]*(i-cur))
      stk.pop()
    stk.append((A[i], cur))

while stk:
  cur = stk[-1][1]
  ans = max(ans, stk[-1][0]*(n-cur))
  stk.pop()

print(ans)