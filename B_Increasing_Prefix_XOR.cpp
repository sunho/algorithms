#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Modular Integer
// does arithmetics (mod P) automatically
const int MOD = 998244353; // 998244353
struct mint {
  int v;
  mint() : v(0) {}
  mint(ll v) : v(v % MOD) { v += (v < 0) * MOD; }
};
mint& operator+=(mint& a, mint b) { if ((a.v += b.v) >= MOD) a.v -= MOD; return a; }
mint& operator-=(mint& a, mint b) { if ((a.v -= b.v) < 0) a.v += MOD; return a; }
mint operator*(mint a, mint b) { return mint((ll) a.v * b.v); }
mint operator+(mint a, mint b) { return a += b; }
mint operator-(mint a, mint b) { return a -= b; }
mint& operator*=(mint& a, mint b) { return a = a * b; }
mint pow(mint a, ll p) { return p == 0 ? 1 : pow(a * a, p / 2) * (p & 1 ? a : 1); }
mint inv(mint a) { return pow(a, MOD - 2); }
mint operator/(mint a, mint b) { return a * inv(b); }

int lg(ll n) {
  int level = 0;
  while (n >>= 1) ++level;
  return level;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  
  ll n,m;
  cin >> n >> m;

  int l = lg(m);
  if (n > 61) {
    cout << 0 << "\n";
    return 0;
  }

  vector<mint> dp(n+1);
  dp[0] = 1;
  for (int i=0;i<=l;i++){
    vector<mint> next(n+1);
    for (int j=0;j<=n;j++){
      next[j] += dp[j];
      if (j >= n) continue;
      if (i != l) {
        next[j+1] += dp[j]*(1ll<<i);
      } else {
        next[j+1] += dp[j]*(((1ll<<i)^m) + 1);
      }
    }
    dp = move(next);
  }
  cout << dp[n].v << "\n";
}
