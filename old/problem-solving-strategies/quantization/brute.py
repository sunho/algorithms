#!/usr/bin/python
# -*- coding: utf-8 -*-
import sys
import random

def short(n):
    m = int(sum(n)/float(len(n))+0.5)
    return sum([(i-m)*(i-m) for i in n])

def qunatize(n,s):
    if len(n) == 0:
        return 0
    if s == 0:
        return sys.maxsize

    res = sys.maxsize
    for i in range(1,len(n)+1):
        res = min(short(n[:i]) + qunatize(n[i:], s-1),res)
    return res

if __name__ == "__main__":
    problems = list()
    for i in range(0,20):
        x = [random.randint(0,1000) for j in range(0,10)]
        y = qunatize(sorted(x),i)
        problems.append((x,i,y))
    print(["{} {} {}".format(" ".join([str(i) for i in p[0]]),p[1],p[2]) for p in problems])
