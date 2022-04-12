struct seg_tree {
  seg_tree(int n, int bias=0) : n(n), bias(bias), a(n*4) {
  }
  seg_tree(vector<int>&v) : n(v.size()), bias(0), a(n*4) {
    build(0, n - 1, 1, v);
  }
  struct node {
    ll sum = 0;
    void update(ll v) {
      sum += v;
    }
  };
  node merge(const node &x, const node &y) {
    node ret;
    ret.sum = x.sum + y.sum;
    return ret;
  }
  void build(int l, int r, int rt, vector<int>& v) {
    if(l == r) {
      a[rt].sum = v[l];
      return;
    }
    int m = (l + r) / 2;
    build(l, m, rt*2,v);
    build(m + 1, r, rt*2+1,v);
    a[rt] = merge(a[rt*2], a[rt*2+1]);
  }
  template <typename... V>
  void update(int pos, int l, int r, int rt, const V&... v) {
    if(l == r) {
      a[rt].update(v...);
      return;
    }
    int m = (l + r) / 2;
    if(pos <= m) update(pos, l, m, rt*2, v...);
    else update(pos, m+1, r, rt*2+1, v...);
    a[rt] = merge(a[rt*2], a[rt*2+1]);
  }
  template <typename... V>
  void update(int pos, const V&... v) {
    pos += bias;
    update(pos, 0, n - 1, 1, v...);
  }
  node query(int L, int R, int l, int r, int rt) {
    if(L <= l && r <= R) return a[rt];
    node ret;
    int m = (l + r) / 2;
    if(L <= m) ret = merge(ret, query(L, R, l, m, rt*2));
    if(m < R) ret = merge(ret, query(L, R, m+1, r, rt*2+1));
    return ret;
  }
  ll query(int L, int R) {
    L += bias, R += bias;
    return query(L, R-1, 0, n - 1, 1).sum;
  }

  int n;
  int bias;
  vector<node> a;
};

struct lazy_seg_tree {
  lazy_seg_tree(int n) : n(n), a(n*4) {
    build(0, n - 1, 1);
  }
  struct node {
    ll sum = 0, add = 0;
    void update(int l, int r, ll v) {
      sum = sum + (r - l + 1) * v;
      add = add + v;
    }
  };
  node merge(const node &x, const node &y) {
    node ret;
    ret.sum = x.sum + y.sum;
    return ret;
  }
  void pushdown(int l, int r, int rt) {
    int m = (l + r) / 2;
    a[rt*2].update(l, m, a[rt].add);
    a[rt*2+1].update(m+1, r, a[rt].add);
    a[rt].add = 0;
  }
  void build(int l, int r, int rt) {
    if(l == r) {
      return;
    }
    int m = (l + r) / 2;
    build(l, m, rt*2);
    build(m + 1, r, rt*2+1);
    a[rt] = merge(a[rt*2], a[rt*2+1]);
  }
  template <typename... V>
  void update(int L, int R, int l, int r, int rt, const V&... v) {
    if(L <= l && r <= R) {
      a[rt].update(l, r, v...);
      return;
    }
    pushdown(l, r, rt);
    int m = (l + r) / 2;
    if(L <= m) update(L, R, l, m, rt*2, v...);
    if(m < R) update(L, R, m+1, r, rt*2+1, v...);
    a[rt] = merge(a[rt*2], a[rt*2+1]);
  }
  template <typename... V>
  void update(int L, int R, const V&... v) {
    update(L, R-1, 0, n - 1, 1, v...);
  }
  node query(int L, int R, int l, int r, int rt) {
    if(L <= l && r <= R) return a[rt];
    node ret;
    pushdown(l, r, rt);
    int m = (l + r) / 2;
    if(L <= m) ret = merge(ret, query(L, R, l, m, rt*2));
    if(m < R) ret = merge(ret, query(L, R, m+1, r, rt*2+1));
    return ret;
  }
  node query(int L, int R) {
    return query(L, R-1, 0, n - 1, 1);
  }

  int n;
  vector<node> a;
};


// faster version
// use when it's slow
template<class T>
struct seg_tree {
  // [-bias, n - bias)
  seg_tree(int n, int bias=0) : n(n), bias(bias), seg(2*n) {}
  seg_tree(const vector<T>& arr, int bias=0) : n(arr.size()), bias(bias), seg(2 * n) {
    for (int i=0;i<n;i++) seg[i+n] = arr[i];
    for (int i = n - 1; i > 0; --i) seg[i] = combine(seg[i*2], seg[i*2+1]);
  }
  T combine(T a, T b) { return a+b; }
  void set(int p, T value) { // set value at position p
    p+=bias,p+=n;
    seg[p] = value;
    for (; p > 1; p /= 2) seg[p/2] = combine(seg[p], seg[p^1]);
  }
  void update(int p, T value) { // set value at position p
    p+=bias,p+=n;
    seg[p]+=value;
    for (; p > 1; p /= 2) seg[p/2] = combine(seg[p], seg[p^1]);
  }
  T query(int l, int r) { // on interval [l, r)
    T res = 0;
    l+=bias,r+=bias;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      if (l&1) res = combine(res, seg[l++]);
      if (r&1) res = combine(res, seg[--r]);
    }
    return res;
  }
private:
  int n;
  int bias;
  vector<T> seg;
};