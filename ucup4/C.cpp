#include <bits/stdc++.h>
#include <queue>
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
  vector<pair<int,int>> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i].first >> A[i].second;
  }

  auto get_dist = [&](pair<int,int> a, pair<int, int> b) {
    ll dx = (ll)a.first-b.first;
    ll dy = (ll)a.second-b.second;
    return dx*dx + dy*dy;
  };
  
  vector<tuple<ll,int,int>> worklist;
  for (int i=0;i<n;i++){
    for (int j=i+1;j<n;j++){
      worklist.push_back({get_dist(A[i],A[j]),i,j});
    }
  }

  sort(begin(worklist), end(worklist));

  vector<vector<int>> edges(n, vector<int>(n));
  union_find uf(n);

  for (auto [d,i,j] : worklist) {
    int u = uf.leader(i), v = uf.leader(j);
    if (u == v) continue;
    edges[u][v]++;
    edges[v][u]++;
    if (edges[u][v] == uf.sz[u]*uf.sz[v]) {
      uf.unite(u,v);
      int nw = uf.leader(u);
      int old = u == nw ? v : u;
      for (int i=0;i<n;i++){
        if (i == old || i == nw) continue;
        edges[i][nw] += edges[i][old];
        edges[nw][i] += edges[old][i];
      }
      cout << uf.sz[nw] << "\n";
    }
  }
}
