struct fenwick_tree {
  int n;
  vector<ll> bits;
  fenwick_tree(int n) : n(n), bits(n+1) {}
  void update(int v, int delta) { 
    for (++v; v <= n; v += v&(-v)) bits[v] += delta;
  }
  ll query(int r) {
    ll res = 0;
    for (++r; r > 0; r -= r&(-r)) res += bits[r];
    return res;
  }
  ll query(int l, int r) { return query(r) - query(l-1); }
};

struct fenwick_tree_2d {
  int n, m;
  vector<vector<ll>> bits;
  fenwick_tree(int n, int m) : n(n), m(m), bits(n+1, vector<ll>(m+1)) {}
  void update(int i, int j, int delta) { 
    for (++i; i <= n; i += i&(-i))
      for (++j; j <= m; j += j&(-j))
        bits[i][j] += delta;
  }
  ll query(int i, int j) {
    ll res = 0;
    for (++i; i > 0; i -= i&(-i))
      for (++j; j > 0; j -= j&(-j))
        res += bits[i][j];
    return res;
  }
  ll query(int i1, int j1, int i2, int j2) { 
    return query(i2, j2) + query(i1, j1) - query(i1,j2) - query(i2,j1); 
  }
};