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
mint& operator*=(mint& a, mint b) { return a = a * b; }
mint pow(mint a, ll p) { return p == 0 ? 1 : pow(a * a, p / 2) * (p & 1 ? a : 1); }
mint inv(mint a) { return pow(a, MOD - 2); }
mint operator/(mint a, mint b) { return a * inv(b); }

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n,m;
  cin >> n >> m;
  array<array<int, 20>,20> adj{};
  for (int i=0;i<m;i++){
    int u,v;
    cin >> u >> v;
    --u,--v;
    adj[u][v]++;
  }

  const int N = 1 << n;
  vector dp(N, array<mint, 20>{});
  dp[1][0] = 1;
  for (int mask=1;mask<N;mask++){
    for (int i=1;i<n;i++){
      if (!(mask & (1 << i))) continue;
      for (int j=0;j<n-1;j++){
        if (i == j) continue;
        if (!(mask & (1 << j))) continue;
        dp[mask][i] += dp[mask ^ (1<<i)][j] * adj[j][i];
      }
    }
  }
  cout << dp[N-1][n-1].v;
}
