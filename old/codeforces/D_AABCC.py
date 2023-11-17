def sieves(N):
  lp = [0] * (N+1)
  pr = []
  for i in range(2,N+1):
    if lp[i] == 0:
      lp[i] = i
      pr.append(i)
    j = 0
    while j < len(pr) and pr[j] <= lp[i] and i*pr[j] <= N:
      lp[i*pr[j]] = pr[j]
      j += 1
  return lp, pr

n = int(input())
N = int(1e6)
lp, pr = sieves(N)
ans = 0
for i in range(len(pr)):
  if pr[i]*pr[i] > n:
    break
  for j in range(i+1, len(pr)):
    if pr[i]*pr[i]*pr[j] > n:
      break
    for k in range(j+1, len(pr)):
      if pr[i]*pr[i]*pr[j]*pr[k]*pr[k] > n:
        break
      ans += 1

print(ans)