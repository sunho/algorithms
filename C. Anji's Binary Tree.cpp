#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<pair<int, int>> adj(n, {-1, -1});
  for (int i = 0; i < n; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    adj[i] = {u, v};
  }
  const int inf = 1e9;
  auto dfs = [&](auto &&self, int u) {
    bool is_leaf = adj[u].first == -1 && adj[u].second == -1;
    if (is_leaf) {
      return 0;
    }
    int cost = inf;
    if (adj[u].first != -1) {
      cost = min(cost, self(self, adj[u].first) + (s[u] == 'L' ? 0 : 1));
    }
    if (adj[u].second != -1) {
      cost = min(cost, self(self, adj[u].second) + (s[u] == 'R' ? 0 : 1));
    }
    return cost;
  };
  cout << dfs(dfs, 0) << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
