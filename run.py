import math
PI = 3.14159265359

L1 = 929.2
L2 = 600.9
MR = 134.1
A = L2 - L1 - 48
B = L2 - MR
D = 6675
s2 = 11.37
s1 = 11.75
w = 1500

wrtD = 16*PI*A*w*(2*B+D)/((B+D)**2*(s2-s1))
wrtL1 = 16*PI*D**2*w/((s2-s1)*(D+L2-MR))
wrtL2 = 16*PI*D**2*w*(D+L1-MR+48)/((s2-s1)*(D+L2-MR)**2)
wrtMR = 16*PI*D**2*w*(L1-L2+48)/((s1-s2)*(D+L2-MR)**2)
wrts2 = 16*PI*D**2*w*(L1-L2+48)/((s2-s1)**2*(D+L2-MR))
wrts1 = -wrts2

a = [wrtD, wrtL1, wrtL2, wrtMR, wrts2, wrts1]
d = [0.5, 0.05, 0.05, 0.05, 0.05, 0.05]

sum = 0
for i in range(len(a)):
    sum += a[i]**2*d[i]**2

print(math.sqrt(sum))
