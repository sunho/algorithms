#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1000000007; // 998244353
struct mint {
  int x;
  mint() : x(0) {}
  mint(ll val) : x(val % MOD) { x += (x < 0) * MOD; }
};
mint& operator+=(mint& a, mint b) { if ((a.x += b.x) >= MOD) a.x -= MOD; return a; }
mint& operator-=(mint& a, mint b) { if ((a.x -= b.x) < 0) a.x += MOD; return a; }
mint operator*(mint a, mint b) { return mint((ll) a.x * b.x); }
mint operator+(mint a, mint b) { return a += b; }
mint operator-(mint a, mint b) { return a -= b; }
mint& operator*=(mint& a, mint b) { return a = a * b; }
mint pow(mint a, ll p) { return p == 0 ? 1 : pow(a * a, p / 2) * (p & 1 ? a : 1); }
mint inv(mint a) { return pow(a, MOD - 2); }
mint operator/(mint a, mint b) { return a * inv(b); }

struct fenwick_tree {
  int n;
  vector<mint> bits;
  fenwick_tree(int n) : n(n), bits(n+1) {}
  void update(int v, mint delta) { 
    for (++v; v <= n; v += v&(-v)) bits[v] += delta;
  }
  mint query(int r) {
    mint res = 0;
    for (++r; r > 0; r -= r&(-r)) res += bits[r];
    return res;
  }
  mint query(int l, int r) { return query(r) - query(l-1); }
};


int main() {
	cin.tie(nullptr)->sync_with_stdio(false);

	int n;
	cin >> n;
	vector<fenwick_tree> dp(12, fenwick_tree(n+1));
	dp[0].update(0,1);
	for (int i=0;i<n;i++){
		int a;
		cin >> a;
		for (int j=1;j<=11;j++) {
			dp[j].update(a, dp[j-1].query(0,a-1));
		}
	}
	cout << dp[11].query(0,n).x << "\n";
}
