#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n,m;
  cin >> n >> m;
  vector adj(n, vector<int>());
  vector<pair<int,int>> ans(m);
  vector odds(n, 0);
  for(int i=0;i<m;i++){
    int u,v;
    cin >> u >> v;
    --u,--v;
    ans[i] = {u,v};
    adj[u].push_back(i);
    adj[v].push_back(i);
  }
  vector<int> vis(n);
  auto dfs = [&](auto self, int u, int p) -> void {
    vis[u] = 2;
    for (int i : adj[u]) {
      auto [x,y] = ans[i];
      int v = x == u ? y : x;
      if (v == p) continue;
      if (vis[v] == 2) {
        odds[u]^=1;
        ans[i] = {u,v};
      } else if (vis[v] == 0) {
        self(self, v, u);
        if (odds[v]) {
          odds[v] ^= 1;
          ans[i] = {v,u};
        } else {
          odds[u] ^= 1;
          ans[i] = {u,v};
        }
      }
    }
    vis[u] = 1;
  };
  dfs(dfs, 0, -1);
  for (int i=0;i<n;i++){
    if (!vis[i]) dfs(dfs, i, -1);
  }
  for (int i=0;i<n;i++){
    if (odds[i]) {
      cout << "IMPOSSIBLE" << "\n";
      return 0;
    }
  }
  for (int i=0;i<m;i++){
    cout << ans[i].first + 1 << " " << ans[i].second + 1 << "\n";
  }
  
}
