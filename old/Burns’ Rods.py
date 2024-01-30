import os
import sys
input = lambda: sys.stdin.readline().rstrip("\r\n")

import sys
from collections import defaultdict, deque
import itertools

def copy(A):
  return [[x for x in y] for y in A]

def rotate(A):
  A = copy(A)
  A[0][1], A[1][1] = A[1][1], A[0][1]
  n = len(A) - 2
  for i in range(n):
    A[i+2][1], A[i+2][3] = A[i+2][3], A[i+2][1]
  for i in range(n//2):
    A[i+2][1], A[2+n-1-i][1] = A[2+n-1-i][1], A[i+2][1]
    A[i+2][2], A[2+n-1-i][2] = A[2+n-1-i][2], A[i+2][2]
    A[i+2][3], A[2+n-1-i][3] = A[2+n-1-i][3], A[i+2][3]
  return A

def flip(A, i):
  A = copy(A)
  n = len(A) - 2
  if i == 0:
    A[0][0], A[0][1] = A[0][1], A[0][0]
  if i == n-1:
    A[1][0], A[1][1] = A[1][1], A[1][0]
  for j in range(3):
    A[i+2][j], A[i+2][j+3] = A[i+2][j+3], A[i+2][j]
  return A

def create(n):
  A = list()
  A.append([0,0])
  A.append([1,1])
  for i in range(n):
    A.append([2,2,4,3,3,5])
  return A

n = 5
A = create(n)
states = []
vis = set()

vis.add(str(A))
states.append(A)

q = deque()
q.append(A)
while q:
  A = q.pop()
  for i in range(n):
    B = flip(A,i)
    if str(B) not in vis:
      vis.add(str(B))
      states.append(B)
      q.append(B)
  B = rotate(A)
  if str(B) not in vis:
    vis.add(str(B))
    states.append(B)
    q.append(B)

pos1 = defaultdict(set)
pos2 = defaultdict(set)

for state in states:
  key = [state[0], state[1], state[2], state[4], state[6]]
  pos1[str(key)].add(str([state[3],state[5]]))
  key2 = [state[0], state[1], state[2], state[6]]
  pos2[str(key2)].add(str([state[3],state[5]]))

def check(A, n):
  found = False
  fronts = list(set([A[0][0], A[0][1], A[1][0], A[1][1]]))
  sides = []
  for i in range(2,n+2):
    sides.append(A[i][2])
    sides.append(A[i][5])
  sides = list(set(sides))
  if len(fronts) != 2:
    return False
  if len(sides) != 2:
    return False
  for i in range(2, n+2):
    for j in range(5):
      if A[i][j] in fronts:
        return False
      if j != 2 and j != 5:
        if A[i][j] in sides:
          return False
  mp = dict()
  mp[fronts[0]] = 0
  mp[fronts[1]] = 1
  mp[sides[0]] = 4
  mp[sides[1]] = 5
  cur = 2
  for i in range(6):
    if i not in fronts and i not in sides:
      mp[i] = cur
      cur += 1
  A = [[mp[x] for x in y] for y in A]
  for P in itertools.permutations([2,3]):
    ok = True
    Q = [0,1]
    for x in P:
      Q.append(x)
    Q.append(4)
    Q.append(5)
    B = [[Q[x] for x in y] for y in A]
    if n % 2 == 1:
      key = str([B[0], B[1], B[2], B[2+n//2], B[-1]])
      for i in range(0,n//2):
        if str([B[i+2],B[2+n-i-1]]) not in pos1[key]:
          ok = False
          break
    else:
      key = str([B[0], B[1], B[2], B[-1]])
      for i in range(0,n//2):
        if str([B[i+2],B[2+n-i-1]]) not in pos2[key]:
          ok = False
          break
    if ok:
      found = True
  if found:
    return True
  return False

while True:
  n = int(input())
  if n == 0:
    break
  A = []
  A.append(list(map(int,input().split())))
  A.append(list(map(int,input().split())))
  for _ in range(n):
    A.append(list(map(int,input().split())))
  if check(A,n):
    print("solvable")
  else:
    print("unsolvable")
      
