import math

n,m = map(int,input().split())
n-=2
print(math.factorial(n)//(math.factorial(n//2)*math.factorial(n//2)*(n//2+1)) % m)
