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

