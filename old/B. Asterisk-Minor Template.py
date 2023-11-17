import sys
input = sys.stdin.readline

t = int(input())

for _ in range(t):
  a = input()[:-1]
  b = input()[:-1]
  if a[0] == b[0]:
    print("YES")
    print(a[0] + '*')
  elif a[-1] == b[-1]:
    print("YES")
    print("*"+b[-1])
  else:
    found = None
    for i in range(len(a)-1):
      for j in range(len(b)-1):
        if a[i:i+2] == b[j:j+2]:
          found = a[i:i+2]
    if found:
      print('YES')
      print('*'+found+'*')
    else:
      print('NO')
