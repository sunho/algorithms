#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  int n;
  cin >> n;
  vector<int> D(n);
  vector<vector<pair<int,int>>> g(n);
  for(int i=0;i<n;i++){
    cin >> D[i];
  }
  for(int i=0;i<n;i++){
    int u,v,w;
    cin >> u >> v >> w;
    --u,--v;
    g[u].push_back({v,w});
    g[v].push_back({u,w});
  }

  ll inf = 1e18;
  vector<vector<ll>> dp(n, vector<ll>(2, -inf));
  auto dfs = [&](int u, int p, auto&& self) {
    int deg = D[u];
    for (auto [v, w] : g[u]) {
      if (v == p) continue;
      self(v, u, self);
      ll cand1 = w + dp[v][0];
      ll cand2 = dp[v][1];
    }
  };
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
