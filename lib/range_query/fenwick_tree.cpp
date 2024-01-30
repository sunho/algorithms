template<typename T=ll>
struct fenwick_tree {
  int n;
  vector<T> bits;
  fenwick_tree(int n) : n(n), bits(n + 1) {}
  void set(int v, T delta) {
    add(v, -get(v,v));
    add(v, delta);
  }
  void add(int v, T delta) {
    for (++v; v <= n; v += v & (-v))
      bits[v] += delta;
  }
  T get(int i) { return query(i,i); }
  T query(int l, int r) { return prefix_query(r) - prefix_query(l - 1); }
  T prefix_query(int r) {
    T res = 0;
    for (++r; r > 0; r -= r & (-r))
      res += bits[r];
    return res;
  }
};

struct range_fenwick_tree {
  int n;
  vector<ll> bits;
  fenwick_tree(int n) : n(n), bits(n + 1) {}
  void add(int l, int r, int val) {
    prefix_add(l, val);
    prefix_add(r + 1, -val);
  }

  void prefix_add(int idx, int val) {
    for (++idx; idx <= n; idx += idx & -idx)
      bits[idx] += val;
  }

  int point_query(int idx) {
    int ret = 0;
    for (++idx; idx > 0; idx -= idx & -idx)
      ret += bits[idx];
    return ret;
  }
};

struct fenwick_tree_2d {
  int n, m;
  vector<vector<ll>> bits;
  fenwick_tree_2d(int n, int m) : n(n), m(m), bits(n + 1, vector<ll>(m + 1)) {}
  void update(int x, int y, int delta) {
    for (int i=x+1;i<=n;i+=i&-i)
      for (int j=y+1;j<=m;j+=j&-j)
        bits[i][j] += delta;
  }
  ll query(int x, int y) {
    ll res = 0;
    for (int i=x+1;i>0;i-=i&-i)
      for (int j=y+1;j>0;j-=j&-j)
        res += bits[i][j];
    return res;
  }
  ll query(int i1, int j1, int i2, int j2) {
    return query(i2, j2) + query(i1-1, j1-1) - query(i1-1, j2) - query(i2, j1-1);
  }
};
