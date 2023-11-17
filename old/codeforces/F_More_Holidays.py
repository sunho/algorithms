n, m, k = map(int, input().split())
s = input()
pf = [0] * (n+1)
for i in range(n):
  pf[i+1] = pf[i] + (s[i] == 'x')

inf = int(1e18)

def sum(r):
  res = (r // n) * pf[n]
  res += pf[r%n]
  return res

def check(l, r):
  return sum(r+1) - sum(l) <= k

def solve(l):
  ok = l
  ng = n*m
  while ng - ok > 1:
    mid = (ok+ng)//2
    if check(l, mid):
      ok = mid
    else:
      ng = mid
  return ok-l+1

ans = 0
for i in range(n):
  ans = max(ans, solve(i))

print(ans)