n = int(input())
s = input()
k = int(input())
if s == "annyong":
  if k % 2 == 0:
    if k == n:
      print(k-1)
    else:
      print(k+1)
  else:
    print(k)
else:
  if k % 2 == 1:
    if k == n:
      print(k-1)
    else:
      print(k+1)
  else:
    print(k)

