from fractions import Fraction

m = int(input())

q = Fraction(m,60)
ans = (3-2*q)*q*q
print("{}/{}".format(ans.numerator, ans.denominator))

