from fractions import Fraction

a,b = map(int, input().split())
c = max(a,b)
f = Fraction(6-c+1,6)
print(str(f.numerator) + "/" + str(f.denominator))
