#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n, h;
  cin >> n >> h;
  vector<vector<pair<int, int>>> adj(n);
  int root = -1;
  for (int i=0;i<n;i++){
    int p,a;
    cin >> p >> a;
    if (p == 0 && a == 0) {
      root = i;
      continue;
    }
    --p;
    adj[p].push_back({i,a});
    adj[i].push_back({p,a});
  }
  vector<ll> mx(n);
  auto dfs = [&](auto&& self, int u, int p, ll d) -> ll {
    mx[u] = d;
    for (auto [v,w] : adj[u]) {
      if (p == v) continue;
      mx[u] = max(mx[u], self(self, v, u, d + w));
    }
    return mx[u];
  };
  dfs(dfs, root, -1, 0);
  ll ans = 0;
  auto dfs2 = [&](auto&& self, int u, int p, ll d) -> void {
    for (auto [v, w] : adj[u]) {
      if (p == v) continue;
      ll nd = d;
      if (mx[v] - d > h) {
        int need = mx[v] - d - h;
        ans += min(need, w);
        nd += min(need, w);
      }
      self(self, v, u, nd);
    }
  };
  dfs2(dfs2, root, -1, 0);
  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
