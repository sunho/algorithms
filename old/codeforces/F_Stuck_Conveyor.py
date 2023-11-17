from sys import stdout
ans = (2,2,'>')
asked = 0
TEST = 0
def query(M, i, j):
  global asked
  asked += 1
  assert asked <= 25
  print("?", i+1, j+1)
  for row in M:
    print(''.join(row))
  stdout.flush()
  if TEST:
    M[ans[0]][ans[1]] = ans[2]
    vis = dict()
    x,y = i,j
    while True:
      if (x,y) in vis:
        print("res: ", -2, -2)
        return (-2,-2)
      if x == -1 or x == n or y == -1 or y == n:
        print("res: ", x, y)
        return (x, y)
      vis[(x,y)] = 1
      dir = M[x][y]
      if dir == '>':
        y+=1
      elif dir == '<':
        y-=1
      elif dir == 'v':
        x+=1
      elif dir == '^':
        x-=1
  else:
    x,y = map(int, input().split())
    return (x-1,y-1)

n = int(input())

snake = []
for i in range(n):
  for j in range(n):
    if i%2 == 0:
      snake.append((i,j))
    else:
      snake.append((i,n-1-j))
if n%2 == 0:
  end = (n-1,-1)
else:
  end = (n-1,n)

def fill_grid():
  global snake
  M = [[">"]*n for i in range(n)]
  for i in range(len(snake)-1):
    if snake[i+1][0] - snake[i][0] == 1:
      dir = 'v'
    elif snake[i+1][0] - snake[i][0] == -1:
      dir = '^'
    elif snake[i+1][1] - snake[i][1] == 1:
      dir = '>'
    else:
      dir = '<'
    M[snake[i][0]][snake[i][1]] = dir
  M[snake[-1][0]][snake[-1][1]] = dir
  return M
M = fill_grid()

def check_dir(x,y):
  M = [[">"]*n for i in range(n)]
  for i in range(n):
    for j in range(n):
      if i == x and j < y:
        M[i][j] = '<'
      if i == x and j > y:
        M[i][j] = '>'
      if i < x and j == y:
        M[i][j] = '^'
      if i > x and j == y:
        M[i][j] = 'v'
  u,v = query(M, x, y)
  if u == -1 and v == y:
    return '^'
  if u == n and v == y:
    return 'v'
  if u == x and v == -1:
    return '<'
  if u == x and v == n:
    return '>'
  assert False

def check(i):
  global M, snake, end
  return query(M, snake[i][0], snake[i][1]) != end

if not check(0):
  snake = list(reversed(snake))
  M = fill_grid()
  end = (0,-1)

ok,ng = -1,len(snake)
while ng-ok > 1:
  mid = (ok+ng)//2
  if check(mid):
    ok = mid
  else:
    ng = mid
x,y = snake[ok]
print("!", x+1, y+1, check_dir(x,y))