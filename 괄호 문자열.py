""" For heavy recursion
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
  

n, k = map(int, input().split())

cache = dict()

@bootstrap
def f(cnt, b, n):
  if (cnt, b, n) in cache:
    yield cache[(cnt, b, n)]
  if n == 0:
    if b == 0:
      if cnt == 0:
        yield 1
      else:
        yield 0
    else:
      yield 0
  if b == 1:
    res = 0
    if cnt == -1:
      res += yield f(cnt+1,0,n-1) 
    res += yield f(cnt+1,1,n-1)
    res += yield f(cnt-1,1,n-1)
    cache[(cnt,b,n)] = res
    yield res
  else:
    if cnt < 0:
      yield 0
    res = 0
    res += yield f(cnt+1,0,n-1)
    res += yield f(cnt-1,0,n-1)
    cache[(cnt,b,n)] = res
    yield res

cnt = 0
done = False
ans = ""
for i in range(n):
  sum = 0
  if done:
    sum = 1 << (n-i-1)
  else:
    for j in range(-n,n+1):
      sum += f(j,1,n-i-1)
      if j+cnt != 1:
        sum += f(j,0,n-i-1)
  if k < sum:
    cnt -= 1
    ans += "("
  else:
    cnt += 1
    ans += ")"
    if cnt > 0: 
      done = True
    k -= sum

if k != 0:
  print(-1)
else:
  print(ans)





