#include <bits/stdc++.h>
#include <queue>
using namespace std;
using ll = long long;

const int inf = 1e9;

// Union Find using disjoint subset union
struct union_find {
  int n;
  int ssc;
  vector<int> p;
  vector<int> sz;
  vector<int> deg;
  vector<set<tuple<int,int,int>>> edges;
  union_find(int n) : n(n), p(n), sz(n, 1), ssc(n), deg(n), edges(n) {
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
    if (sz[u] < sz[v]) {
      swap(u,v);
    }
    p[v] = u;
    sz[u] += sz[v];
    for (auto [d, x, y] : edges[v]) {
      edges[u].insert({d,x,y});
    }

    ssc--;
    return true;
  }
};

void solve() {
  int n,m;
  cin >> n >> m;
  union_find uf(n);
  vector adj(n, set<pair<int,int>>());
  for (int i=0;i<n;i++) cin >> uf.deg[i];
  while (m--){
    int u,v;
    cin >> u >> v;
    --u,--v;
    if (uf.deg[u] > uf.deg[v]) {
      swap(u,v);
    }
    uf.edges[u].insert({uf.deg[v], u, v});
    uf.edges[v].insert({uf.deg[u], v, u});
  }
  
  for (int i=0;i<n;i++){
    if (uf.deg[i] != 0) continue;
    set<pair<int,int>> pq;
    pq.insert({uf.deg[i], i});
    while (!pq.empty()) {
      auto [d, u] = *pq.begin();
      pq.erase(pq.begin());
      int gu = uf.find_p(u);
      if (!uf.edges[gu].size()) continue;
      auto [dd,x,y] = *uf.edges[gu].begin();
      if (uf.find_p(x) == uf.find_p(y)) {
        uf.edges[gu].erase(uf.edges[gu].begin());
        pq.insert({uf.deg[u], u});
        continue;
      }
      int k = uf.sz[gu];
      if (k >= dd) {
        pq.insert({uf.deg[y], y});
        uf.unite(x, y);
      }
    }
  }

 
  if (uf.ssc == 1) {
    cout << "YES" << "\n";
  } else {
   cout << "NO" << "\n";
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int t;
  cin >> t;
  while(t--)
    solve();

}
