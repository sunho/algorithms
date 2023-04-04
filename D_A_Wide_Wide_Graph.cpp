#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Union Find using disjoint subset union
struct union_find {
  int n;
  vector<int> p;
  vector<int> sz;
  int scc;
  union_find(int n) : n(n), p(n), sz(n, 1), scc(n) {
    iota(begin(p),end(p), 0);
  }
  
  // return the representitive node of connected component
  int find_p(int x) {
    if (p[x] == x)
      return x;
    // path compression: cache the parent finding
    return p[x] = find_p(p[x]);
  }

  // join the components that x and y belong to
  bool unite(int x, int y) {
    int u = find_p(x);
    int v = find_p(y);
    if (u == v) return false;
    // size heuristic: connect smaller tree to larger tree
    if (sz[u] > sz[v]) {
      swap(u,v);
    }
    scc--;
    p[v] = u;
    sz[u] += sz[v];
    return true;
  }
};

void solve() {
  int n;
  cin >> n;
  vector adj(n, vector<int>());
  for (int i=0;i<n-1;i++){
    int u,v;
    cin >> u >> v;
    --u,--v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int max_level = 0;
  int max_i = 0;
  auto dfs = [&](auto self, int u, int p, int level) -> void {
    if (level > max_level) {
      max_level = level;
      max_i = u;
    }
    for (int v : adj[u]) {
      if (v == p) continue;
      self(self, v, u, level+1);
    }
  };
  dfs(dfs, 0, -1, 0);
  int p1 = max_i;
  max_level=0,max_i=p1;
  dfs(dfs, max_i, -1, 0);
  int p2 = max_i;
  auto get_dist = [&](int start) {
    vector<int> dist(n);
    auto dfs = [&](auto self, int u, int p, int level) -> void {
      dist[u] = level;
      for (int v : adj[u]) {
        if (v == p) continue;
        self(self, v,u,level+1);
      }
    };
    dfs(dfs, start, -1, 0);
    return dist;
  };
  auto dist1 = get_dist(p1), dist2 = get_dist(p2);
  vector<vector<int>> todo1(n+1);
  vector<vector<int>> todo2(n+1);
  for (int i=0;i<n;i++){
    todo1[dist1[i]].push_back(i);
    todo2[dist2[i]].push_back(i);
  }
  
  union_find uf(n);
  vector<int> ans(n);
  for (int d=n;d>=1;d--) {
    for (int v : todo1[d]) {
      uf.unite(p1, v);
    }
    for (int v : todo2[d]) {
      uf.unite(p2, v);
    }
    ans[d-1] = uf.scc;
  }
  for (int i=0;i<n;i++){
    cout << ans[i] << " ";
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  
  solve();  
  
}
