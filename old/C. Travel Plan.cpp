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

vector<vector<mint>> dp(62, vector<mint>(1));
mint pow2[128];

int32_t ilog2(ll u) {
  return 63 - __builtin_clzll(u);
}

void solve() {
  ll n;
  int m;
  cin >> n >> m;
  auto dep1 = [&](ll u) {
    int level = 0;
    while (u <= n) {
      u *= 2;
      level++;
    }
    return level;
  };
  auto dep2 = [&](ll u) {
    int level = 0;
    while (u <= n) {
      u *= 2;
      u += 1;
      level++;
    }
    return level;
  };
  vector<mint> ans(129);
  auto dfs = [&](auto&& self, ll u) -> vector<mint> {
    vector<vector<mint>> dist(2, vector<mint>(1));
    int ff = 0;
    for (int z : {0,1}) {
      dist[z][0] = 1;
      if (dep1(2*u+z) == 0) continue;
      if (dep1(2*u+z) == dep2(2*u+z)) {
        mint d = 1;
        int lg2 = dep1(2*u+z)-1;
        for (int i=0;i<=lg2;i++){
          dist[z].push_back(d);
          d*=2;
        }
        for (int l=1;l<=2*lg2+1;l++) {
          ans[l] += dp[lg2][l];
        }
      } else {
        dist[z] = self(self, u*2+z);
        ff++;
      }
    }
    vector<mint> res(max(dist[0].size(),dist[1].size())+1);
    res[0] = 1;
    res[1] = 1;
    for (int l1=0;l1<dist[0].size();l1++) {
      for (int l2=0;l2<dist[1].size();l2++){
        ans[l1+l2+1] += dist[0][l1] * dist[1][l2];
      }
    }
    for (int l1=1;l1<dist[0].size();l1++) {
      res[l1+1] += dist[0][l1];
    }
    for (int l2=1;l2<dist[1].size();l2++) {
      res[l2+1] += dist[1][l2];
    }
    return res;
  };
  dfs(dfs, 1);
  mint fin = 0;
  for (int a=1;a<=m;a++) {
    mint aa = a;
    mint aa_inv = a-1;
    mint mm = pow(mint(m),n-1);
    mint mm_inv = inv(mint(m));
    for (int l=1;l<ans.size();l++){
      if (ans[l].x == 0) continue;
      if (n-l < 0) break;
      fin += a*(aa-aa_inv)*mm*ans[l];
      aa*=a;
      aa_inv*=a-1;
      mm *= mm_inv;
    }
  }
  cout << fin.x << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  pow2[0] = 1;
  for (int i=1;i<128;i++){
    pow2[i] = pow2[i-1]*2;
  }

  vector<vector<mint>> dist(62, vector<mint>(1));
  dp[0] = {0,1};
  dist[0] = {1,1};
  for (int i=1;i<62;i++){
    dp[i] = vector<mint>(2*i+2);
    for (int l=1;l<=2*i+1;l++){
      if (l < dp[i-1].size()) {
        dp[i][l] += 2*dp[i-1][l];
      }
    }
    for (int l1=0;l1<=i;l1++){
      for (int l2=0;l2<=i;l2++){
        dp[i][l1+l2+1] += pow2[max(l1-1,0)]*pow2[max(l2-1,0)];
      }
    }
  }
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
