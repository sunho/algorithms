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
  int n,m;
  cin >> n >> m;
  vector<vector<mint>> dp(m+1, vector<mint>(m+1));
  for (int i=0;i<=m;i++) {
    dp[i][m] = m-i;
  }
  // (x,y) -> (x+1, y), (x, y+1)
  for (int i=0;i<=m;i++){
    dp[i][i] = 0;
  }
  for (int i=m-1;i>=0;i--){
    for (int j=m-1;j>=i+1;j--){
      dp[i][j] = (dp[i+1][j] + 1)/2 + (dp[i][j+1])/2;
    }
  }
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
    A[i]--;
  }
  mint ans = 0;
  for (int i=0;i<n-1;i++){
    ans += dp[A[i]][A[i+1]];
  }
  ans += m - A.back();
  cout << ans.x << "\n";
}
