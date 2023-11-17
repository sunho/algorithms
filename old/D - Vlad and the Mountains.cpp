#include <bits/stdc++.h>

using namespace std;

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
  vector<int> H(n);
  for (int i=0;i<n;i++){
    cin >> H[i];
  }
  for (int i=0;i<m;i++){
    int u,v;
    cin >> u >> v;
    --u,--v;
    edges.push_back({max(H[u], H[v]), u, v});
  }
  sort(begin(edges),end(edges));
  int q;
  cin >> q;
  vector<tuple<int,int,int,int>> queries;
  for (int i=0;i<q;i++){
    int s,t,e;
    cin >> s >> t >> e;
    --s,--t;
    queries.push_back({H[s]+e,s,t,e});
  }
  vector<int> id(q);
  iota(begin(id),end(id),0);
  sort(begin(id),end(id),[&](int i, int j) {
    return queries[i] < queries[j];
  });
  sort(begin(queries),end(queries));
  vector<int> ans(q);
  union_find uf(n);
  int cur = 0;
  for (int i=0;i<q;i++){
    auto [h, s, t, e] = queries[i];
    while (cur < edges.size() && get<0>(edges[cur]) <= h) {
      auto [_,u,v] = edges[cur];
      uf.unite(u,v);
      cur++;
    }
    if (H[t] - H[s] <= e && uf.leader(t) == uf.leader(s)) {
      ans[id[i]] = 1;
    }
  }
  for (int i=0;i<q;i++){
    if (ans[i]) {
      cout << "YES" << "\n";
    } else {
      cout << "NO" << "\n";
    }
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
