#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n,m;
  cin >> n >> m;
  vector<vector<array<int,2>>> adj(n);
  for (int i=0;i<m;i++){
    int u,v,w;
    cin >> u >> v >> w;
    --u,--v;
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
  }
  auto check = [&](ll lim) {
    vector<int> C(n,-1);
    auto dfs = [&](auto&& self, int u, int col) -> bool {
      if (C[u] != -1) {
        if (col == C[u]) {
          return true;
        } else {
          return false;
        }
      }
      C[u] = col;
      for (auto [v,w] : adj[u]) {
        if (w >= lim) continue;
        if (!self(self, v, col^1)) {
          return false;
        }
      }
      return true;
    };
    for (int i=0;i<n;i++){
      if (C[i] == -1) {
        if (!dfs(dfs, i, 0)) {
          return false;
        }
      }
    }
    for (int i=0;i<n;i++){
      vector<int> dist;
      for (auto [v,w] : adj[i]) {
        if (w >= lim) continue;
        dist.push_back(w);
      }
      ranges::sort(dist);
      if (dist.size() >= 2 && dist[0] + dist[1] < lim) {
        return false;
      }
    }
    return true;
  };
  const int inf = 1e9;
  ll ok = 0, ng = 2*inf+1;
  while (ng-ok>1) {
    ll mid = (ok+ng)/2;
    if (check(mid)) ok = mid;
    else ng = mid;
  }
  cout << ok << "\n";
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
