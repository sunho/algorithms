#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, m;
  cin >> n >> m;
  vector adj(n, vector<int>());
  for (int i=0;i<m;i++){
    int a, b;
    cin >> a >> b;
    --a,--b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  vector color(n, false);
  vector vis(n, 0);
  bool cycle = false;
  auto dfs = [&](int u, int p, auto&&self) -> void {
    vis[u] = 1;
    for (int v : adj[u]) {
      if (v == p) continue;
      if (vis[v]) {
        if (color[v] == color[u]) {
          cycle = true;
          return;
        } else {
          continue;
        }
      }
      color[v] = !color[u];
      self(v, u, self);
    }
  };
  for (int i=0;i<n;i++){
    if(!vis[i])
      dfs(i, -1, dfs);
  }
  if (cycle) {
    cout << "IMPOSSIBLE" << "\n";
    return;
  }
  for (int i=0;i<n;i++){
    cout << color[i] + 1 << " ";
  }
  cout << "\n";
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
