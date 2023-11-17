#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n);
  for (int i=0;i<m;i++){
    int u,v;
    cin >> u >> v;
    --u,--v;
    adj[v].push_back(u);
  }
  vector<bool> vis(n);
  auto dfs = [&](auto&& self, int u) -> void {
    if (vis[u]) return;
    vis[u] = true;
    for (int v : adj[u]) {
      self(self, v);
    }
  };
  for (int u=0;u<n;u++){
    bool ok = true;
    for (int v=0;v<n;v++){
      if (u == v) continue;
      vis.assign(n, false);
      dfs(dfs, v);
      if (!vis[u]) ok = false;
    }
    if (ok) {
      cout << u+1 << "\n";
      return 0;
    }
  }
  cout << -1 << "\n";
}
