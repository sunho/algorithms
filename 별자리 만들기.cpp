#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  multiset<int> nodes;
  for (int i = 0; i < n; i++) {
    int m;
    cin >> m;
    vector<vector<int>> adj(m);
    for (int j = 0; j < m - 1; j++) {
      int u, v;
      cin >> u >> v;
      --u, --v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    int h = nodes.empty() ? 0 : *nodes.begin();
    if (!nodes.empty()) {
      nodes.erase(nodes.begin());
    }
    auto dfs = [&](auto &&self, int u, int p, int d) -> void {
      if (p != -1 && adj[u].size() == 1) {
        nodes.insert(h + d);
      }
      for (int v : adj[u]) {
        if (v == p)
          continue;
        self(self, v, u, d + 1);
      }
    };
    dfs(dfs, 0, -1, 1);
  }
  cout << *--nodes.end() << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
