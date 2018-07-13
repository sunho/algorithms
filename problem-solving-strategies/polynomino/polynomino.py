#!/usr/bin/python
# -*- coding: utf-8 -*-

MOD = 10000000

"""
n = remaining block s = last number of blocks
count(n,s) = sum(for i <- 1 to n count(n-i,i) * classify(i,s)
classify(i,s) = the number of cases for i blocks below s blocks
"""
def count(n, s, memo = None):
    if n == 0:
        return 1

    if memo is None:
        memo = [[None]*(n+1) for y in range(n+1)]

    if memo[n][s] is not None:
        return memo[n][s]

    res = 0
    for i in range(1,n+1):
        res = (res + count(n-i, i, memo) * (1 if s==0 else i + s - 1)) % MOD

    memo[n][s]=res
    return res

if __name__ == "__main__":
    n = input()
    print(count(int(n),0))
