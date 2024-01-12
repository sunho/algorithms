""" For heavy recursion
"""
from types import GeneratorType


def bootstrap(f, stack=[]):
    def wrappedfunc(*args, **kwargs):
        if stack:
            return f(*args, **kwargs)
        else:
            to = f(*args, **kwargs)
            while True:
                if type(to) is GeneratorType:
                    stack.append(to)
                    to = next(to)
                else:
                    stack.pop()
                    if not stack:
                        break
                    to = stack[-1].send(to)
            return to

    return wrappedfunc


n, m = map(int, input().split())

adj = [[] for _ in range(n)]

for i in range(m):
    B = list(map(int, input().split()))
    for j in range(B[0] - 1):
        u = B[j + 1] - 1
        v = B[j + 2] - 1
        adj[u].append(v)
        adj[v].append(u)

cycles = []
cycle_id = [-1] * n

vis = [0] * n
prd = [-1] * n
prd_used = [0] * n

ok = True


@bootstrap
def dfs(u, p):
    global ok
    if vis[u] == 2:
        cur = p
        id = len(cycles) + 1
        cnt = 1
        while cur != u:
            cycle_id[cur] = id
            if prd_used[cur]:
                print(0)
                exit(0)
            prd_used[cur] = 1
            cur = prd[cur]
            cnt += 1
        cycle_id[u] = id
        cycles.append(cnt)
        yield
    elif vis[u] == 1:
        yield
    prd[u] = p
    vis[u] = 2
    for v in adj[u]:
        if v == p:
            continue
        yield dfs(v, u)
    vis[u] = 1
    yield


dfs(0, -1)
if any(v == 0 for v in vis):
    ok = False

if not ok:
    print(0)
else:
    ans = 1
    for c in cycles:
        ans *= c + 1
    print(ans)
