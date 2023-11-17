n = int(input())
A = list(map(int, input().split()))

N = 250000
dp = [-1] * (N+1)

dp[0] = 0
for i in range(n):
    a = A[i]
    next = [-1] * (N+1)
    for j in range(N+1):
        if dp[j] == -1:
            continue
        if abs(j-a) <= N:
            next[abs(j-a)] = max(dp[j]+max(0,a-j), next[abs(j-a)])
        if j + a <= N:
            next[j+a] = max(dp[j]+a, next[j+a])
        next[j] = max(dp[j], next[j])
    dp = next

if dp[0] == 0:
    print(-1)
else:
    print(dp[0])