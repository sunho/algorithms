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
  int n,m;
  cin >> n >> m;
  UnionFind uf(n);
  int max_size = 1;
  for (int i=0;i<m;i++){
    int a,b;
    cin >> a >> b;
    --a,--b;
    uf.unite(a, b);
    max_size = max(max_size, uf.sz[uf.find_p(a)]);
    cout << uf.scc << " " << max_size << "\n";
  }
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
