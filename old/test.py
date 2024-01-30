from collections import defaultdict, deque

q = deque()
q.append((5, 19))

vis = set()
vis.add((5, 19))
S = defaultdict(lambda: [])


def push(x):
    global q
    global vis
    (a, b) = x
    if a > int(1e3) or b > int(1e3):
        return
    if x not in vis:
        vis.add(x)
        S[a].append(x)
        q.append(x)


while q:
    t = q.pop()
    (x, y) = t
    if x % 2 == 0 and y % 2 == 0:
        push((x // 2, y // 2))
    push((x + 1, y + 1))
    for s in S[y]:
        push((x, s[1]))


for i in range(int(1e8)):
    if (1, i) in vis:
        print(i)
