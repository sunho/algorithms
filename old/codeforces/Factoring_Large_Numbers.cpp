#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

ull modepow(ull a, ull n, ull m) {
  ull res = 1;
  while (n) {
    if (n&1) res = res * a % m;
    a = a * a % m;
    n /= 2;
  }
}

bool isPrime(ull n) {
	if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
	ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
	    s = __builtin_ctzll(n-1), d = n >> s;
	for (ull a : A) {   // ^ count trailing zeroes
		ull p = modpow(a%n, d, n), i = s;
		while (p != 1 && p != n - 1 && a % n && i--)
			p = modmul(p, p, n);
		if (p != n-1 && i != s) return 0;
	}
	return 1;
}


int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
}
