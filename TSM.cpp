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

struct edge{
  int u, v, w;
  bool operator<(edge const& other) const {
    return w < other.w;
  }
};

vector<edge> get_mst(int n, vector<edge> edges, ll& cost) {
  vector<edge> result;
  union_find uf(n);
  sort(edges.begin(), edges.end());
  for (edge e : edges) {
    if (uf.leader(e.u) != uf.leader(e.v)) {
        cost += e.w;
        result.push_back(e);
        uf.unite(e.u, e.v);
    }
  }
  return result;
}

struct range_edge {
  int u,v,l,r;
};

void solve() {
  int n,m;
  ll k;
  cin >> n >> m;
  cin >> k;
  
  vector<range_edge> edges;
  ll mn = 0, mx = 0;
  for (int i=0;i<m;i++){
    int u,v,l,r;
    cin >> u >> v >> l >> r;
    --u,--v;
    mn += l;
    mx += r;
    edges.push_back({u,v,l,r});
  }
  auto create_graph = [&](ll S) -> vector<edge> {
    ll rem = S - mn;
    if (rem < 0) return {};
    vector<edge> g;
    for (int i=0;i<m;i++){
      int w = edges[i].r-edges[i].l;
      int k = min((ll)w,rem);
      g.push_back({edges[i].u,edges[i].v,edges[i].l+k});
      rem -= k;
    }
    return g;
  };
  auto check = [&](ll S) {
    vector<edge> g = create_graph(S);
    if (g.size() < n - 1) return false;
    ll cost = 0;
    auto g2 = get_mst(n, g, cost);
    if (g2.size() != n-1) return false;
    return cost >= k;
  };
  ll ng = -1, ok = 1e18;
  while (ok-ng>1){
    ll mid = (ok+ng)/2;
    if (check(mid)) ok = mid;
    else ng = mid;
  }
  auto g = create_graph(ok);
  ll cost = 0;
  auto g2 = get_mst(n, g, cost);
  if (g2.size() != n-1 || cost != k) {
    cout << "NO" << "\n";
    return;
  }
  cout << "YES" << "\n";
  for (auto e : g) {
    cout << e.w << "\n";
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
