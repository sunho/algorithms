t = int(input())

S = ''

for i in range(1,100):
  if i%3 == 0 and i%5 == 0:
    S += 'FB'
  elif i%3 == 0:
    S += 'F'
  elif i%5 == 0:
    S += 'B'

for _ in range(t):
  n = int(input())
  s = input()
  ok = False
  for i in range(len(S)):
    if S[i:i+n] == s:
      ok = True
  if ok:
    print('YES')
  else:
    print('NO')
