t = int(input())

for _ in range(t):
  a,b,c,d = map(int, input().split())
  if a == 0:
    print(1)
    continue
  ans = 0
  mm = min(b,c)
  ans += 2*mm
  b -= mm
  c -= mm
  rem = b+c+d
  mm2 = min(rem,a)
  ans += 2*mm2
  rem -= mm2
  a -= mm2
  ans += a
  if rem > 0:
    ans += 1
  print(ans)
