import math
def is_const(x):
  (a,b,c,d) = x
  return a == 0 and c == 0

def fraction(x,y):
  return (0, x, 0, y)

def neg(x):
  (a,b,c,d) = x
  return (-a,-b,c,d)

def simplify(x):
  if is_const(x):
    (a,b,c,d) = x
    if d < 0:
      b *= -1
      d *= -1
    return (0, b//math.gcd(b,d), 0, d//math.gcd(b,d))
  else:
    return x

ban = []
stk = []
for cmd in input().split():
  if cmd == 'X':
    stk.append((1,0,0,1))
  elif cmd == '*':
    rhs = stk.pop()
    lhs = stk.pop()
    if is_const(lhs):
      lhs,rhs = rhs,lhs
    (a,b,c,d) = lhs
    (_,p,_,q) = rhs
    stk.append((p*a,p*b,q*c,q*d))
  elif cmd == '+' or cmd == '-':
    rhs = stk.pop()
    lhs = stk.pop()
    if cmd == '-':
      rhs = neg(rhs)
    if is_const(lhs):
      lhs,rhs = rhs,lhs
    (a,b,c,d) = lhs
    (_,p,_,q) = rhs
    stk.append((q*a+p*c,q*b+p*d,q*c,q*d))
  elif cmd == '/':
    rhs = stk.pop()
    lhs = stk.pop()
    if not is_const(rhs):
      (_,p,_,q) = lhs
      (a,b,c,d) = rhs
      if a != 0:
        ban.append(fraction(-b,a))
        stk.append((p*c,p*d,q*a,q*b))
      else:
        stk.append((p*c,p*d,0,q*b))
    else:
      (a,b,c,d) = lhs
      (_,p,_,q) = rhs
      stk.append((q*a,q*b,p*c,p*d))
  else:
    val = ord(cmd)-ord('0')
    stk.append((0,val,0,1))

(a,b,c,d) = stk[0]
if a == 0:
  if b == 0:
    print("MULTIPLE")
  else :
    print("NONE")
else:
  ans = simplify(fraction(-b,a))
  (_,p,_,q) = ans
  ok = True
  for b in ban:
    if simplify(b) == ans:
      ok = False
  if not ok:
    print("NONE")
  else:
    print("X = {}/{}".format(p,q))
