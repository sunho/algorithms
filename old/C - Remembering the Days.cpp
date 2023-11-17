#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  int n,m;
  cin >> n >> m;
  vector<vector<pair<int,int>>> adj(n);
  for (int i=0;i<m;i++){
    int u,v,w;
    cin >> u >> v >> w;
    --u,--v;
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
  }
  vector<bool> vis(n);
  ll cur = 0;
  ll ans = 0;
  auto dfs = [&](auto&& self, int u) -> void {
    vis[u] = true;
    ans = max(ans, cur);
    for (auto [v,w] : adj[u]) {
      if (vis[v]) continue;
      cur += w;
      self(self, v);
      cur -= w;
    }
    vis[u] = false;
  };
  for (int i=0;i<n;i++){
    dfs(dfs,i);
  }
  cout << ans << "\n";
}
