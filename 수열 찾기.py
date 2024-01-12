from fractions import Fraction
n = int(input())
A = list(map(int,input().split()))
S = set(A)
sum = 0
for i in range(n):
  sum += Fraction(1,A[i]+1)
if (sum == 1 and len(S) == n) or sum < 1:
  print(1)
else:
  print(0)
