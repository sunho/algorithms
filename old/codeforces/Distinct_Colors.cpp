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

  int n;
  cin >> n;
  vector<int> colors(n);
  for (int i=0;i<n;i++) cin >> colors[i];

  vector adj(n, vector<int>());
  for (int i=0;i<n-1;i++){
    int u,v;
    cin >> u >> v;
    --u,--v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> tin(n);
  vector<int> tout(n);
  int timer = 0;
  auto dfs = [&](auto self, int u, int p) -> void {
    tin[u] = timer;
    for (int v : adj[u]){
      if (v == p) continue;
      self(self, v, u);
    }
    tout[u] = timer++;
  };
  dfs(dfs, 0, -1);
  vector<int> tours(n);
  for (int i=0;i<n;i++){
    tours[tout[i]] = i;
  }

  vector<int> ans(n);
  fenwick_tree ft(n);
  map<int,int> last_index;
  for (int i=0;i<n;i++){
    int u = tours[i];
    if (last_index.count(colors[u])) {
      ft.update(last_index[colors[u]], -1);
    }
    last_index[colors[u]] = i;
    ft.update(i, 1);
    ans[u] = ft.query(tin[u], i);
  }

  for (int i=0;i<n;i++){
    cout << ans[i] << " ";
  }
}
