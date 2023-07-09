import random
import sys
input = sys.stdin.readline

M = 10**6

TEST = 0
ptr = 0
N = 612
hidden = [i+1 for i in range(N)]
random.shuffle(hidden)

def query(k):
  global ptr, hidden, N
  if TEST:
    res = hidden[ptr]
    ptr += k
    ptr %= N
    return res
  else:
    print("+", k)
    sys.stdout.flush()
    return int(input())

mx = 1
k = 395
for i in range(k):
  mx = max(mx, query(random.randint(1,M)))
ans = mx

cur = 0
loc = dict()
d = 300
for i in range(d):
  q = query(1)
  if q in loc:
    print("!", cur - loc[q])
    exit(0)
  loc[q] = cur
  cur += 1

q = query(mx)
if q in loc:
  print("!", cur - loc[q])
  exit(0)
cur += mx

for i in range(d):
  q = query(d)
  if q in loc:
    print("!", cur - loc[q])
    exit(0)
  cur += d

assert False