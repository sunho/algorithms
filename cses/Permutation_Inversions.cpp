#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1000000007; // 998244353
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

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n, k;
  cin >> n >> k;
  vector<mint> dp(k+1);
  dp[0] = 1;
  for (int i=0;i<n;i++){
    vector<mint> next(k+1);
    mint sum = 0;
    for (int j=0;j<=k;j++){
      sum += dp[j];
      next[j] += sum;
      if (j-i>=0)
        sum -= dp[j-i];
    }
    dp = move(next);
  }
  cout << dp[k].v << "\n";
}
