import itertools
import math
arr = []
area = 0
for i in range(4):
    w, h = map(int, input().split())
    arr.append((w,h))
    area += w*h


side = int(math.sqrt(area))
if side * side != area:
    print(0)
    exit(0)

def merge_rect(a,b,dir):
    if a == (0,0):
        return b
    if b == (0,0):
        return a
    if dir:
        if a[0] == b[0]:
            return (a[0], a[1]+b[1])
        else:
            return (-1,-1)
    else:
        if a[1] == b[1]:
            return (a[0]+b[0], a[1])
        else:
            return (-1,-1)

def merge(b, dir):
    r = (0,0)
    for i in range(0,len(b)):
        r = merge_rect(r, b[i], dir)
    return r

def check(b):
    if merge([b[0], merge(b[1:4], True)], False) == (side, side):
        return True
    if merge([b[0], b[1], merge(b[2:4], True)], False) == (side, side):
        return True
    if merge([merge(b[0:2], True), merge(b[2:4], True)], False) == (side, side):
        return True
    if merge([merge([merge(b[0:2], False), b[2]], True), b[3]], False) == (side, side):
        return True
    if merge(b, False) == (side, side):
        return True
    return False

for mask in range(1<<4):
    b = arr.copy()
    for i in range(4):
        if mask & (1<<i):
            x, y = arr[i]
            b[i] = (y,x)
    for p in itertools.permutations(b):
        if check(p):
            print(1)
            exit(0)

print(0)