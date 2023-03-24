#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n,m;
  cin >> n >> m;
  vector adj(n, vector<int>());
  while (m--) {
    int a,b;
    cin >> a >> b;
    --a,--b;
    adj[b].push_back(a);
  }
  vector<int> vis(n);
  vector<int> order;
  auto dfs = [&](int u, auto&& self) -> void {
    vis[u] = 2;
    for (int v : adj[u]) {
      if (vis[v] == 2) {
        cout << "IMPOSSIBLE" << "\n";
        exit(0);
      } else if (vis[v] == 1) {
        continue;
      }
      self(v, self);
    }
    order.push_back(u);
    vis[u] = 1;
  };
  for (int i=0;i<n;i++){
    if (!vis[i])
      dfs(i,dfs);
  }
  //reverse(begin(order), end(order));
  for (int i=0;i<n;i++){
    cout << order[i] + 1 << " ";
  }
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
