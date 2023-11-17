#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 998244353;
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

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	string S;
	cin >> S;
	int n = S.size();
	vector<mint> dp(n+1);
	dp[0] = 1;
	for (int i=0;i<n;i++){
		vector<mint> nxt(n+1);
		if (S[i] == '(') {
			for (int j=0;j<n;j++) nxt[j+1] += dp[j];
		} else if (S[i] == ')'){
			for (int j=1;j<=n;j++) nxt[j-1] += dp[j];
		} else {
			for (int j=0;j<=n;j++) {
				if (j - 1 >= 0)
					nxt[j-1] += dp[j];
				if (j + 1 <= n)
					nxt[j+1] += dp[j];
			}
		}
		dp = nxt;
	}
	cout << dp[0].x << "\n";
}
