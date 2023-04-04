#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n,q;
  cin >> n >> q;
  vector<int> prd(n);
  vector adj(n, vector<int>());
  for (int i=1;i<n;i++){
    cin >> prd[i];
    prd[i]--;
    adj[prd[i]].push_back(i);
  }
  vector<array<int, 32>> up(n);
  int l = ceil(log2(n+1));
  for (int i=0;i<l;i++){
    for (int j=0;j<n;j++){
      if (i == 0)
        up[j][i] = prd[j];
      else
        up[j][i] = up[up[j][i-1]][i-1];
    }
  }

  int time = 0;
  vector<int> tin(n);
  vector<int> tout(n);
  auto dfs = [&](auto self, int u, int p) -> void {
    tin[u] = time++;
    for (int v : adj[u]) {
      if (v == p) continue;
      self(self, v, u);
    }
    tout[u] = time++;
  };
  dfs(dfs, 0, -1);
  auto is_ancestor = [&](int u, int v) -> bool {
    return tin[u] <= tin[v] && tout[v] <= tout[u];
  };

  while(q--){
    int u,v;
    cin >> u >> v;
    --u,--v;
    if (is_ancestor(u, v)){
      cout << u + 1 << "\n";
      continue;
    }
    for (int i=l-1;i>=0;i--){
      if (!is_ancestor(up[u][i], v))
        u = up[u][i];
    }
    cout << up[u][0] + 1 << "\n";
  }
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
