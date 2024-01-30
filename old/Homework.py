import itertools

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

s = input()
n = len(s)
mp = [0]*n
stk = []
for i in range(n):
    if s[i] == '(':
        stk.append(i)
    elif s[i] == ')':
        mp[stk[-1]] = i
        mp[i] = stk[-1]
        stk.pop()

@bootstrap
def f(sl, sr):
    if sl == sr:
        yield (0,0,1)
    else:
        if s[sr-1] == '?':
            R = yield f(sr-1,sr-1)
        else:
            R = yield f(mp[sr-1]-3,sr-1)
        if s[sl+4] == '?':
            L = yield f(sl+4,sl+4)
        else:
            L = yield f(sl+4,mp[sl+7])
        l1,r1,n1 = L
        l2,r2,n2 = R
        n = n1+n2
        # print(s[sl:sr+1])
        # print(l1,r1,n1)
        # print(l2,r2,n2)
        if s[sl:sl+3] == 'min':
            yield (min(l1,l2),l1+l2+r1-l1+r2-l2, n)
        else:
            rr1 = n1-r1-1
            rr2 = n2-r2-1
            yield (n-1-(rr1+rr2+r2-l2+r1-l1),n-1-min(rr1,rr2),n)

l,r,_=f(0,n-1)
print(r-l+1)
