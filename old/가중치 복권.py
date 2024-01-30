from fractions import Fraction
n,m,k = map(int, input().split())
cnt = [0] * (n+1)
for i in range(m-1):
  a,b,c = map(int,input().split())
  cnt[a]+=1
  cnt[b]+=1
  cnt[c]+=1

def ipow(x, n):
  res = 1
  for i in range(n):
    res *= x
  return res


mx = (0, 0, 0, 0)
for i in range(1,n+1):
  for j in range(i+1,n+1):
    for z in range(j+1,n+1):
      P = [0] * (n+1)
      cnt[i] += 1
      cnt[j] += 1
      cnt[z] += 1
      P[i] = Fraction(cnt[i], 3*m)
      P[j] = Fraction(cnt[j], 3*m)
      P[z] = Fraction(cnt[z], 3*m)
      cnt[i] -= 1
      cnt[j] -= 1
      cnt[z] -= 1
      prob = ipow(1-P[i]-P[j]-P[z],k)*(P[i]+P[j]+P[z])
      mx = max(mx, (prob, i, j, z))

print(mx[0].numerator, mx[0].denominator)
print(mx[1], mx[2], mx[3])
