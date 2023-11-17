#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// Modular Integer
// does arithmetics (mod P) automatically
int MOD;
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

void solve() {
  int n,k;
  cin >> n >> k;
  cin >> MOD;
  mint ans = 0;
  for (int tgt=0;tgt<k;tgt++){
    vector<mint> dp(k);
    dp[0] = 1;
    for (int i=0;i<n;i++){
      vector<mint> nxt(k);
      for (int sum=0;sum<k;sum++){
        for (int c=0;c<k;c++){
          if (2*c % k != tgt) {
            nxt[(sum+c)%k] += dp[sum];
          }
        }
      }
      dp = nxt;
    }
    ans += dp[tgt];
  }
  cout << (pow(mint(k),n) - ans).x << "\n";
}

int main() {
  solve();
}
