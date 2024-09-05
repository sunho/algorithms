def f(x):
  return x*x-2

ll = 1
r = 2

for i in range(64):
  m = (ll+r)/2
  if f(ll)*f(m) < 0:
    r = m
  else:
    ll = m

print((ll+r)/2)
