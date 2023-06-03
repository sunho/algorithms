n = int(input())
lines = [input() for _ in range(n)]

def check(t):
    indent = -1
    level = 0
    for i in range(n):
        space = 0
        open = False
        for c in lines[i]:
            if c == '{':
                open = True
            elif c == '}':
                level -= 1
            elif c == 's':
                space += 1
            elif c == 't':
                space += t
        if indent == -1 and level == 1:
            indent = space
        if level != 0 and indent*level != space:
            return False
        if open:
            level += 1
    return True

for t in range(1,1001):
    if check(t):
        print(t)
        exit(0)

print(-1)