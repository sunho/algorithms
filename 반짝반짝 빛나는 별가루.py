n,k,c,r = map(int,input().split())
base = list(map(int,input().split()))
s = list(map(int,input().split()))
p = list(map(int,input().split()))
skill = [0]*k
combo = 0
hp = 0
ans = 0
for i in range(n):
  l = int(input())
  if l == 0:
    combo = 0
    hp -= r
    hp = max(0,hp)
    continue
  l -= 1
  ans += (base[l]*(100+combo*c))*(100+skill[l]*s[l])//10000
  skill[l] += 1
  hp += p[l]
  combo+=1
  if hp > 100:
    print(-1)
    exit(0)
print(ans)
