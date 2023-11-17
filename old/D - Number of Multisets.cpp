#include <bits/stdc++.h>

using namespace std;

using ll = long long;

// Modular Integer
// does arithmetics (mod P) automatically
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
  int n, k;
  cin >> n >> k;
  const int N = 1<<13;
  vector<vector<mint>> dp(n+1, vector<mint>(N+1));
  for (int i=0;i<=n;i++) {
    for (int j=N;j>=0;j--) {
      if (j >= i) {
        dp[i][j] = j==i;
      } else {
        if (j > 0)
          dp[i][j] += dp[i-1][j-1];
        if (j*2 <= N)
          dp[i][j] += dp[i][j*2];
      }
    }
  }
  cout << dp[n][k].x << "\n";
}
