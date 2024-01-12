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

void solve() {
  int n,m;
  cin >> n >> m;
  vector<tuple<int,int,int>> edges;
  for (int i=0;i<m;i++){
    int u,v,w;
    cin >> u >> v >> w;
    --u,--v;
    edges.push_back({u,v,w});
  }
  int t1,t;
  cin >> t1 >> t;
  --t1,--t;
  auto check = [&](int s) {
    union_find uf(n);
    for (int i=0;i<m;i++){
      auto [u,v,w] = edges[i];
      if (w >= s) {
        uf.unite(u,v);
      }
    }
    return uf.leader(t1) == uf.leader(t);
  };
  
  int ok = -1, ng = (int)1e9 + 1;
  while (ng-ok>1){
    int mid = (ok+ng)/2;
    if (check(mid)) ok = mid;
    else ng = mid;
  }
  cout << ok << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
