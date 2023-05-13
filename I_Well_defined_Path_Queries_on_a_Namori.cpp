#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Union Find using disjoint subset union
struct union_find {
  int n;
  vector<int> p;
  vector<int> sz;
  union_find(int n) : n(n), p(n), sz(n, 1) {
    iota(begin(p),end(p), 0);
  }
  int leader(int x) {
    if (p[x] == x)
      return x;
    return p[x] = leader(p[x]);
  }
  void unite(int x, int y) {
    int l = leader(x), s = leader(y);
    if (l == s) return;
    if (sz[s] > sz[l]) swap(s,l);
    p[s] = l, sz[l] += sz[s];
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n;
  cin >> n;

  vector adj(n, vector<int>());

  for (int i=0;i<n;i++){
    int u,v;
    cin >> u >> v;
    --u,--v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  set<int> cycle;
  vector<int> prd(n);
  vector<int> color(n);
  auto dfs = [&](auto self, int u, int p) -> void { 
    color[u] = 2;
    for (int v : adj[u]) {
      if (v == p) continue;
      prd[v] = u; 
      if (color[v] == 2) {
        for (int cur = prd[u]; cur != u; cur = prd[cur])
          cycle.insert(cur);
        cycle.insert(u);
      } else if (color[v] == 0) {
        self(self, v, u);
      }
    }
    color[u] = 1;
  };
  dfs(dfs, 0, -1);

  union_find uf(n);
  for (int u=0;u<n;u++){
    for (int v : adj[u]) {
      if (cycle.count(u) && cycle.count(v)) continue;
      uf.unite(u, v);
    }
  }

  int q;
  cin >> q;
  while (q--){
    int s,t;
    cin >> s >> t;
    --s,--t;
    if (uf.leader(s) != uf.leader(t)) {
      cout << "No" << "\n";
      continue;
    }
    cout << "Yes" << "\n";
  }

}
