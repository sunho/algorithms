"""
For heavy recursion
"""
from types import GeneratorType
def bootstrap(f, stack=[]):
  def wrappedfunc(*args, **kwargs):
    if stack:
      return f(*args, **kwargs)
    else:
      to = f(*args, **kwargs)
      while True:
        if type(to) is GeneratorType:
          stack.append(to)
          to = next(to)
        else:
          stack.pop()
          if not stack:
            break
          to = stack[-1].send(to)
      return to
  return wrappedfunc
  
n = int(input())
A = list(map(int,input().split()))

dp = dict()

@bootstrap
def f(x):
  if sorted(x) == x:
    yield 0
  global dp
  key = ''.join([str(a) for a in x])
  if key in dp:
    yield dp[key]
  cnt = 0
  S = 0
  for i in range(len(x)):
    for j in range(i+1,len(x)):
      if x[i] > x[j]:
        x[i], x[j] = x[j], x[i]
        S += yield f(x)
        cnt += 1
        x[i], x[j] = x[j], x[i]
  dp[key] = 1 / cnt * S + 1
  yield dp[key]

print(f(A))
