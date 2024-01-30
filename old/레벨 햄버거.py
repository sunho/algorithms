n, k = map(int, input().split())
k -= 1
def f(n):
  if n == 0:
    return (1,1)
  a,b = f(n-1)
  return (2*a + 3, 2*b+1)

def g(n,k):
  if n == 0:
    return 1
  if k == 0:
    return 0
  x,y = f(n-1)
  k -= 1
  if k < x:
    return g(n-1, k)
  if k == x:
    return y+1
  return y + 1 + g(n-1,k-x-1)

print(g(n,k))
  
