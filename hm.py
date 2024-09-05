

def f(n):
  inf = int(1e9)
  dp = [-inf] * (n+1)
  A = []
  for i in range(1,n+1):
    if n % i == 0 and i != 1:
      A.append(n//i)
  A = list(set(A))
  A = sorted(A)
  dp[0] = 0 
  prev = [-1] * (n+1)
  for a in A:
    for i in reversed(range(1,n+1)):
      if i - a >= 0:
        if dp[i-a] != -inf and dp[i] < dp[i-a] + 1:
          prev[i] = (i-a, a)
          dp[i] = dp[i-a] + 1
  if dp[n] != -inf:
    cur = n
    ans = []
    while cur != 0:
      ans.append(n//prev[cur][1])
      cur = prev[cur][0]
    return ans
  return None

mx = 0
# for i in range(100000,100500):
#   res = f(i)
#   if res:
#     print(i, res)
#     mx = max(mx,len(res))
for i in range(1,100):
  res = f(64*i)
  if res:
    print(i, len(res))
