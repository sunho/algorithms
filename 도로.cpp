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
  vector<vector<int>> adj(n, vector<int>(n));
  for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){
      char c;
      cin >> c;
      adj[i][j] = c == 'Y';
    }
  }
  vector<pair<int,int>> edges;
  for (int i=0;i<n;i++){
    for (int j=i+1;j<n;j++){
      if (adj[i][j]) {
        edges.push_back({i,j});
      }
    }
  }
  
  vector<bool> used(edges.size());
  vector<int> deg(n);
  union_find uf(n);
  int mst = 0;
  for (int i=0;i<edges.size();i++) {
    auto [x,y] = edges[i];
    if (uf.leader(x) != uf.leader(y)) {
      used[i] = true;
      deg[x]++, deg[y]++;
      uf.unite(x,y);
      mst++;
    }
  }
  if (mst != n-1) {
    cout << -1 << "\n";
    return;
  }
  int rem = m - mst;
  for (int i=0;i<edges.size();i++){
    auto [x,y] = edges[i];
    if (rem && !used[i]) {
      used[i] = true;
      rem--;
      deg[x]++,deg[y]++;
    }
  }
  if (rem > 0) {
    cout << -1 << "\n";
    return;
  }
  for (int i=0;i<n;i++){
    cout << deg[i] << " ";
  }
  cout << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
