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

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n;
  cin >> n;
  vector<int> A(n);
  for (int i=0;i<n;i++) cin >> A[i];
  mint ans = 0;

  for (int m=1;m<=n;m++){
    vector<vector<mint>> dp(m+1, vector<mint>(m));
    dp[0][0] = 1;
    for (int i=0;i<n;i++){
      vector<vector<mint>> next(m+1, vector<mint>(m));
      for (int j=0;j<=m;j++){
        for (int z=0;z<m;z++){
          if (j + 1 <= m) next[j+1][(z+A[i])%m]+=dp[j][z];
          next[j][z]+=dp[j][z];
        }
      }
      dp = move(next);
    }
    ans += dp[m][0];
  }
  cout << ans.v << "\n";
}
