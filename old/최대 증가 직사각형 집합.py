import heapq
import sys
import bisect
input = sys.stdin.readline

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
  

class seg_tree:
  def __init__(self, n):
    self.n = n
    self.nodes = [0 for _ in range(4*n)]

  @bootstrap
  def query_(self, v, l, r, x, y):
    if l > y or r < x:
      yield 0
    if x <= l and r <= y:
      yield self.nodes[v]
    m = (l+r) // 2
    L = yield self.query_(v*2,l,m,x,y)
    R = yield self.query_(v*2+1,m+1,r,x,y)
    yield max(L,R)

  def query(self, l, r):
    return self.query_(1,0,self.n-1,l,r)
  
  @bootstrap
  def update_(self, v, l, r, x, a):
    if l == r:
      self.nodes[v] = max(self.nodes[v], a)
      yield
    m = (l+r)//2
    if x <= m:
      yield self.update_(v*2,l,m,x,a)
    else:
      yield self.update_(v*2+1,m+1,r,x,a)
    self.nodes[v] = max(self.nodes[v*2], self.nodes[v*2+1])
    yield

  def update(self, x, a):
    self.update_(1,0,self.n-1,x,a)

n = int(input())
A = []
ys = []
for _ in range(n):
  x1,y1,x2,y2 = map(int,input().split())
  ys.append(y1)
  ys.append(y2)
  A.append(((x1,y1),(x2,y2)))

ys = sorted(set(ys))
A.sort()
st = seg_tree(len(ys))
pq = []
for p1,p2 in A:
  x1,y1 = p1
  while pq and pq[0][0] < x1:
    _,y,val = pq[0]
    st.update(bisect.bisect(ys, y), val)
    heapq.heappop(pq)
  val = st.query(0,bisect.bisect_left(ys, y1))
  heapq.heappush(pq, (p2[0],p2[1],val+1))

while pq:
  _,y,val = pq[0]
  st.update(bisect.bisect(ys, y), val)
  heapq.heappop(pq)

print(st.query(0,len(ys)-1))
