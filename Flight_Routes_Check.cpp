#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n,m;
  cin >> n >> m;
  vector adj(n, vector<int>());
  vector adj_inv(n, vector<int>());
  for (int i=0;i<m;i++){
    int a,b;
    cin >> a >> b;
    --a,--b;
    adj[a].push_back(b);
    adj_inv[b].push_back(a);
  }
  vector<int> order;
  vector<int> vis(n);
  auto dfs = [&](auto self, int u) -> void {
    vis[u] = true;
    for (int v : adj[u]){
      if (!vis[v])
        self(self, v);
    }
    order.push_back(u);
  };
  for (int i=0;i<n;i++){
    if (!vis[i])
      dfs(dfs, i);
  }
  reverse(begin(order), end(order));
  vis.assign(n, false);
  vector<vector<int>> components;
  auto dfs2 = [&](auto self, int u) -> void {
    components.back().push_back(u);
    vis[u] = true;
    for (int v : adj_inv[u]){
      if (!vis[v])
        self(self, v);
    }
  };
  for (int i : order) {
    if (!vis[i]) {
      components.push_back({});
      dfs2(dfs2, i);
    }
  }
  if (components.size() != 1) {
    cout << "NO" << "\n";
    cout << components[1].back() + 1 << " " << components[0].back() + 1 << "\n";
    return;
  }
  cout << "YES" << "\n";
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
