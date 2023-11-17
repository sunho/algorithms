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
  vector<mint> dp(2);
  dp[0] = 1;
  for (int i=0;i<n;i++){
    vector<mint> nxt(2);
    int a,b;
    cin >> a >> b;
    if (b == 1) {
      nxt[1] += dp[0];
      nxt[1] += (m-1)*dp[1];
      nxt[0] += (m-1)*dp[0];
    } else {
      nxt[1] += (m-1)*dp[0];
      nxt[1] += dp[1];
      nxt[0] += dp[0];
    }
    dp = nxt;
  }
  cout << (dp[0] + dp[1]).x << "\n";
}
