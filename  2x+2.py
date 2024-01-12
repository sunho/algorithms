n = int(input())

def f(m):
  if m <= 0:
    return 0
  if m % 2 == 1:
    return f(m-1) + 1
  return f((m-1)//4 - 1) + m - (m//2-1)

print(f(n))

