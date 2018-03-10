# objective

gcd(a,b)

# theory

## Euclid's GCD Therom

gcd(a,b) = gcd(a,b mod a) or gcd(a,r) (if b>a)

### prove
if G is gcd(a,b), a/G and b/G are relatively prime. So in
```
a = GA
b = GB
```
A and B are relatively prime.
```
b = aq + r
GB = GAq + r
r = GB - GAq
r = G(B-Aq)
```
Thus G is cd of r and a and if B-Aq and A are relatively prime, G is gcd(a,r)

suppose gcd(A, B-Aq)=m and A=mk B-Aq=ml
```
B = ml + Aq
B = ml + mkq
B = m(l+kq)
A = mk
```
since A and B are relatively prime, gcd(A,B) = 1, since cd can't be lower than 1, m = 1

and if gcd(A, B-Aq) = 1, A and B-Aq are relactively prime.

 .
. . gcd(a,b) = gcd(a,b mod a)

since gcd(a,0) = a

gcd(a,b) = gcd(b mod a, a)
         = a if a is 0

and since a always decrease and is a positive integer, a always reach 0, thus the recursive function always terminate.