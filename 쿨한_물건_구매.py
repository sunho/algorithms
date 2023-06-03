D, A, B = map(int, input().split())

ans = int(1e18)
if A < B:
    A,B = B,A
ans = min(ans, (D + A - 1) // A * A)
ans = min(ans, (D + B - 1) // B * B)
if D >= A*B:
    D2 = D % (A*B) + A*B
    i = 0
    while i*A <= D2:
        y = (D - i*A + B - 1) // B
        ans = min(ans, i*A + B*y)
        i += 1
else:
    i = 0
    while i*A <= D:
        y = (D - i*A + B - 1) // B
        ans = min(ans, i*A + B*y)
        i += 1

print(ans)