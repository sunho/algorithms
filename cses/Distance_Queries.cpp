#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;
  vector adj(n, vector<int>());
  for (int i=0;i<n-1;i++){
    int u,v;
    cin >> u >> v;
    --u,--v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> prd(n+1);
  vector<int> tin(n), tout(n);
  int time = 0;
  auto dfs = [&](auto self, int u, int p) -> void {
    prd[u] = p;
    tin[u] = time++;
    for (int v : adj[u]) {
      if (v == p) continue;
      self(self, v, u);
    }
    tout[u] = time++;
  };
  dfs(dfs, 0, 0);
  
  int l = ceil(log2(n));
  vector<array<int,32>> up(n);
  for (int i=0;i<l;i++){
    for (int j=0;j<n;j++){
      if (i == 0)
        up[j][i] = prd[j];
      else
        up[j][i] = up[up[j][i-1]][i-1];
    }
  }

  auto is_ancestor = [&](int u, int v) {
    return tin[u] <= tin[v] && tout[v] <= tout[u];
  };

  while(q--){
    int u,v;
    cin >> u >> v;
    --u,--v;
    int dist0 = 0, dist1 = 0;
    int lca = u;
    if (!is_ancestor(u, v)) {
      for (int i=l-1;i>=0;i--){
        if (!is_ancestor(up[lca][i], v)) {
          dist0 += 1 << i;
          lca = up[lca][i];
        }
      }
      lca = up[lca][0];
            dist0++;
    }
    if (!is_ancestor(v, u)) {
      for (int i=l-1;i>=0;i--){
        if (is_ancestor(lca, up[v][i]) && up[v][i] != 0) {
          dist1 += 1 << i;
          v = up[v][i];
        }
      }
      if (lca == 0) {
        dist1 ++;
      }
    }
    cout << dist0 + dist1 << "\n";
  }

}
