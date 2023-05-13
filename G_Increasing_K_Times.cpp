#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 998244353; // 998244353
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
  int n, k;
  cin >> n >> k;
  vector<mint> dp(k+1);
  map<int,int> cnt;
  for (int i=0;i<n;i++){
    int a;
    cin >> a;
    cnt[a]++;
  }
  int sz = 0;
  for (auto [a,c] : cnt) {
    if (sz == 0) {
      dp[0] = 1;
      for (int i=1;i<=c;i++) dp[0] *= i;
      sz += c;
      continue;
    }
    for (int i=0;i<c;i++){
      vector<mint> next(k+1);
      for (int j=0;j<=k;j++){
        if (j+1 <= k) {
          next[j+1] += dp[j]*max(sz-j,0);
        }
        next[j] += dp[j]*(j+i+1);
      }
      dp = move(next);
    }
    sz += c;
  }
  cout << dp[k].x << "\n";
}
