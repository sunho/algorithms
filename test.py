x1 = 11
y1 = 58
x2 = 100
y2 = 120
S = set()
for i in range(x1,y1+1):
  for j in range(x2,y2+1):
    S.add(i|j)

print(S)
print(x1 | x2, y1 | y2)
