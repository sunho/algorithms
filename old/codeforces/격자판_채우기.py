n, m = map(int, input().split())

MOD = 9901
M = 1 << m
dp = [[-1 for _ in range(M)] for _ in range(n)]
def f(i, j, mask, nxt):
  if i == n:
    if mask == 0:
      return 1
    else:
      return 0
  if j == 0 and dp[i][mask] != -1:
    return dp[i][mask]
  if j == m:
    return f(i+1, 0, nxt, 0)
  res = 0
  if j + 2 <= m and not mask & (0b11<<j):
    res += f(i, j+2, mask, nxt)
    res %= MOD
  if not mask & (0b1<<j):
    res += f(i, j+1, mask, nxt|(0b1<<j))
    res %= MOD
  else:
    res += f(i, j+1, mask, nxt)
    res %= MOD
  if j == 0:
    dp[i][mask] = res
  return res

print(f(0,0,0,0))
