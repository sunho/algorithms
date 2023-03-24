#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Union Find using disjoint subset union
struct UnionFind {
  int n;
  vector<int> p;
  vector<int> sz;
  int scc;
  UnionFind(int n) : n(n), p(n), sz(n, 1), scc(n) {
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
  int n, m;
  cin >> n >> m;
  UnionFind uf(n);
  vector<tuple<int,int,int>> edges(m);
  for (int i=0;i<m;i++){
    int a,b,w;
    cin >> a >> b >> w;
    --a,--b;
    edges[i] = {a,b,w};
  }

  sort(begin(edges), end(edges), [&](auto& x, auto &y) {
    return get<2>(x) < get<2>(y);
  });

  ll ans = 0;
  for (int i=0;i<m;i++){
    auto [u,v,w] = edges[i];
    if (uf.find_p(u) != uf.find_p(v)) {
      ans += w;
      uf.unite(u, v);
    }
  }
  if (uf.scc != 1){
    cout << "IMPOSSIBLE" << "\n";
    return;
  }
  cout << ans << "\n";
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
