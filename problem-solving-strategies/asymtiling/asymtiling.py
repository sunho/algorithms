#!/usr/bin/python
# -*- coding: utf-8 -*-

N = 1000000007


def tiling(n):
    if n == 0:
        return 1
    if n == 1:
        return 1
    dp0 = dp1 = 1
    for x in range(2, n+1):
        temp = dp1
        dp1 = dp0 + dp1
        dp0 = temp

    return dp1


def asymtiling(n):
    sym = 0
    if n % 2 == 0:
        sym += tiling((n-2)/2)
        sym += tiling(n/2)
    else:
        sym += tiling((n-1)/2)

    return (tiling(n) - sym) % N


if __name__ == "__main__":
    import sys
    n = int(sys.argv[1])
    print(asymtiling(n))
