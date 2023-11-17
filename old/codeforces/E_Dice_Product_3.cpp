#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const int MOD = 998244353; // 998244353
struct mint {
  int x;
  mint(int x = 0) : x(norm(x)) { }
  mint(ll x) : x(norm(x%MOD)) { }
  int norm(int x) const { if (x < 0) { x += MOD; } if (x >= MOD) { x -= MOD; } return x; }
  mint operator+(mint o) const { return norm(x + o.x); }
  mint operator-(mint o) const { return norm(x - o.x); }
  mint operator*(mint o) const { return ll(x) * o.x; }
	mint operator/(mint o) { return *this * o.inv(); }
  mint inv() const { return exp(MOD - 2); }
	mint exp(ll n) const {
		if (!n) return mint(1);
		mint a = *this;
		mint r = a.exp(n / 2); r = r * r;
		return n&1 ? a * r : r;
	}
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  ll n;
	cin >> n;
	map<ll, mint> dp;
	dp[n] = 1;
	auto f = [&](auto self, ll x) -> mint {
		if (x > n) return 0;
		if (dp.count(x)) return dp[x];
		mint res = 0;
		for (int i=2;i<=6;i++)
			res = res + self(self, i*x)/6;
		res = res * mint(6)/5;
		return dp[x] = res;
	};
	cout << f(f,1).x << "\n";
}
