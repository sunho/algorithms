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
  vector<int> components(n);
  int cur_comp = 0;
  auto dfs2 = [&](auto self, int u) -> void {
    components[u] = cur_comp;
    vis[u] = true;
    for (int v : adj_inv[u]){
      if (!vis[v])
        self(self, v);
    }
  };
  for (int i : order) {
    if (!vis[i]) {
      dfs2(dfs2, i);
      cur_comp++;
    }
  }
  cout << cur_comp << "\n";
  for (int i=0;i<n;i++){
    cout << components[i] + 1 << " ";
  }
  
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
