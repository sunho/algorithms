# objective

x^y mod n 

# theory

x^y = x^(2^0) ... x^(2^n)

Since in binary, y is y is sum of every 1 << i (where i binary place of y is 1), y = 2^0 ... 2^n.

So (y >> i) % 2 == 1

And since n * 2 = n << 1, (x^n)^2 = x^(n*2) = x^(n<<1)

So

x^y = (x^(y<<1))^2 (if y%2 == 0)
    = x*(x^(y<<1))^2 (if y%2 == 1)
