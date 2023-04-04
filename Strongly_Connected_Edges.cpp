#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n,m;
  cin >> n >> m;
  vector adj(n, set<int>());
  vector adj2(n, vector<int>());
  while(m--){
    int a,b;
    cin >> a >> b;
    --a,--b;
    adj[a].insert(b);
    adj[b].insert(a);
  }
  vector<pair<int,int>> ans;
  const int inf = 1e9;
  vector<bool> vis(n);
  bool ok = true;
  int last = 0;
  auto dfs = [&](auto self, int u, int p, int level, int max_level) -> void {
    vis[u] = true;
    for (auto it = adj[u].begin(); it != adj[u].end();) {
      int v = *it;
      if (v == p) {
        ++it;
        continue;
      }
      if (!vis[v]) {
        adj2[v].push_back(u);
        ans.push_back({u,v});
        self(self, v, u, level+1, max_level);
        ++it;
      } else {
        ans.push_back({u,v});
        adj2[v].push_back(u);
        adj[v].erase(u);
        it = adj[u].erase(it);
      }
    }
  };
  dfs(dfs, 0, -1, 0, 0);
  for (int i=0;i<n;i++)
    if (!vis[i])
      ok = false;
  vis.assign(n, false);
  auto dfs2 = [&](auto self, int u) -> void {
    vis[u] = true;
    for (int v : adj2[u]) {
      if (!vis[v])
        self(self, v);
    }
  };
  dfs2(dfs2, 0);
  for (int i=0;i<n;i++)
    if (!vis[i])
      ok = false;
  if (!ok) {
    cout << "IMPOSSIBLE" << "\n";
  } else {
    for (auto [u,v] : ans) {
      cout << u + 1 << " " << v + 1 << "\n";
    }
  }
}
