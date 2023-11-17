#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct fenwick_tree {
  int n;
  vector<ll> bits;
  fenwick_tree(int n) : n(n), bits(n+1) {}
  void update(int v, int delta) { 
    for (++v; v <= n; v += v&(-v)) bits[v] += delta;
  }
  ll query(int r) {
    ll res = 0;
    for (++r; r > 0; r -= r&(-r)) res += bits[r];
    return res;
  }
  ll query(int l, int r) { return query(r) - query(l-1); }
};


int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, c;
  cin >> n >> c;
  --c;
  vector<vector<int>> adj(n);
  for (int i=0;i<n-1;i++){
    int u,v;
    cin >> u >> v;
    --u,--v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  fenwick_tree ft(n);
  vector<int> tin(n), tout(n), levels(n);
  int time = 0;
  auto dfs = [&](auto&& self, int u, int p, int lvl) -> void {
    tin[u] = time++;
    levels[u] = lvl;
    for (int v : adj[u]){
      if (v == p) continue;
      self(self, v, u, lvl+1);
    }
    tout[u] = time-1;
  };
  dfs(dfs, c, -1, 1);
  int q;
  cin >> q;
  while(q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int u;
      cin >> u;
      --u;
      ft.update(tin[u], 1);
    } else {
      int v;
      cin >> v;
      --v;
      cout << (ll)levels[v]*ft.query(tin[v], tout[v]) << "\n";
    }
  }
}
