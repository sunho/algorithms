
while True:
    n, m = map(int, input().split())
    if n == 0 and m == 0:
        break
    A = [input() for _ in range(n)]

    d = 1 if n >= 2 else 0

    expr = ''

    def isqrt(n):
        if n == 0:
            return 0
        i = 1
        while i*i != n:
            i += 1
        return i

    i = 0
    while i < m:
        if n >= 2:
            j = i
            while j < m and A[0][j] == '_':
                j+=1
            if j-i >= 1:
                expr += str(isqrt(eval(A[1][i:j])))
                i = j
                continue
        if n >= 3:
            j = i
            while j < m and A[1][j] == '=':
                j+=1
            if j-i >= 1:
                expr += str(int(eval(A[0][i:j]))//int(eval(A[2][i:j])))
                i = j
                continue
        if A[d][i] != '\\' and A[d][i] != '/':
            expr += A[d][i]
            i += 1
        else:
            i += 1
    input()
    print(int(eval(expr)))