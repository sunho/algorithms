t = int(input())

for _ in range(t):
  n = int(input())
  A = list(map(int, input().split()))
  evens = [a % 2 == 0 for a in A]
  if n % 2 == 0:
    if not any(evens):
      print(0)
    else:
      print(1)
  else:
    def solve(A):
      evens = [a % 2 == 0 for a in A]
      if all(evens):
        return solve([a//2 for a in A])
      else:
        if any(evens):
          return 1
        else:
          return 0
    print(solve(A))
