#include <bits/stdc++.h>

using namespace std;

using ll = long long;

// Modular Integer
// does arithmetics (mod P) automatically
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

int main() {
  int n;
  cin >> n;
  int a,b,c,d;
  cin >> a >> b >> c >> d;

  const int N = 1e4;
  vector<mint> facts(N);
  vector<mint> ifacts(N);
  facts[0] = 1;
  ifacts[0] = 1;
  for (int i=1;i<N;i++) {
    facts[i] = i*facts[i-1];
    ifacts[i] = inv(facts[i]);
  }

  vector<vector<mint>> dp(n+1,vector<mint>(n+1));
  dp[0][0] = 1;
  for (int i=0;i<=n;i++) {
    for (int j=0;j<n;j++) {
      if (a <= j + 1 && j + 1 <= b) {
        for (int k=1;i+(j+1)*k<=n;k++) {
          if (c <= k && k <= d) {
            int rem = n-i;
            dp[i+k*(j+1)][j+1] += dp[i][j]*facts[rem]*pow(ifacts[j+1],k)*ifacts[k]*ifacts[rem-k*(j+1)];
          }
        }
      }
      dp[i][j+1] += dp[i][j];
    }
  }
  cout << dp[n][n].x << "\n";
}
