t = int(input())
for _ in range(t):
  n = int(input())
  A = list(map(int, input().split()))
  mx = A.index(max(A))
  two = A.index(2)
  one = A.index(1)
  if one < two and two < mx:
    print(two+1, mx+1)
  if one < mx and mx < two:
    print(one+1, one+1)
  if two < one and one < mx:
    print(one+1, mx+1)
  if two < mx and mx < one:
    print(one+1, one+1)
  if mx < one and one < two:
    print(one+1,mx+1)
  if mx < two and two < one:
    print(two+1, mx+1)