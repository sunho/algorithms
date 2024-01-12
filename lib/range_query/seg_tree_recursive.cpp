// Segment Tree
const int inf = 1e9;
template <typename Info> struct seg_tree {
  int n;
  vector<Info> info;
  seg_tree(int n) : n(n), info(4 * n, Info()) {
    auto build = [&](auto &&self, int v, int l, int r) {
      if (l == r) {
        return;
      } else {
        int m = (l + r) / 2;
        self(self, v * 2, l, m);
        self(self, v * 2 + 1, m + 1, r);
        info[v] = info[v * 2] + info[v * 2 + 1];
      }
    };
    build(build, 1, 0, n - 1);
  }
  void pull(int v) { info[v] = info[v * 2] + info[v * 2 + 1]; }
  void update(int v, int l, int r, int x, const Info &val) {
    if (l == r) {
      info[v] = val;
      return;
    }
    int m = (l + r) / 2;
    if (x <= m)
      update(v * 2, l, m, x, val);
    else
      update(v * 2 + 1, m + 1, r, x, val);
    pull(v);
  }
  void update(int x, const Info &val) { update(1, 0, n - 1, x, val); }
  Info query(int v, int l, int r, int x, int y) {
    if (l > y || r < x)
      return Info();
    if (l >= x && r <= y)
      return info[v];
    int m = (l + r) / 2;
    pull(v);
    return query(2 * v, l, m, x, y) + query(2 * v + 1, m + 1, r, x, y);
  }
  Info query(int l, int r) { return query(1, 0, n - 1, l, r); }
};
struct node {
  ll val = inf;
  friend node operator+(node lhs, node rhs) { return {min(lhs.val, rhs.val)}; }
};

// Lazy Segment Tree
template <class Info, class Tag> struct lazy_seg_tree {
  int n;
  vector<Info> info;
  vector<Tag> lazy;
  lazy_seg_tree(int n) : n(n), info(4 * n), lazy(4 * n) {
    auto build = [&](auto &&self, int v, int l, int r) {
      if (l == r) {
        return;
      } else {
        int m = (l + r) / 2;
        self(self, v * 2, l, m);
        self(self, v * 2 + 1, m + 1, r);
        info[v] = info[v * 2] + info[v * 2 + 1];
      }
    };
    build(build, 1, 0, n - 1);
  }
  void apply(int v, const Tag &tag) {
    info[v].apply(tag);
    lazy[v].apply(tag);
  }
  void push(int v) {
    apply(2 * v, lazy[v]);
    apply(2 * v + 1, lazy[v]);
    lazy[v] = {};
  }
  void pull(int v) { info[v] = info[2 * v] + info[2 * v + 1]; }
  void update(int v, int l, int r, int x, const Info &val) {
    if (l == r) {
      info[v] = val;
      return;
    }
    int m = (l + r) / 2;
    push(v);
    if (x <= m)
      update(2 * v, l, m, x, val);
    else
      update(2 * v + 1, m + 1, r, x, val);
    pull(v);
  }
  void update(int x, const Info &val) { update(1, 0, n - 1, x, val); }
  void range_apply(int v, int l, int r, int x, int y, const Tag &tag) {
    if (l > y || r < x)
      return;
    if (l >= x && r <= y) {
      apply(v, tag);
      return;
    }
    int m = (l + r) / 2;
    push(v);
    range_apply(2 * v, l, m, x, y, tag);
    range_apply(2 * v + 1, m + 1, r, x, y, tag);
    pull(v);
  }
  void range_apply(int l, int r, const Tag &tag) {
    range_apply(1, 0, n - 1, l, r, tag);
  }
  Info query(int v, int l, int r, int x, int y) {
    if (l > y || r < x)
      return {};
    if (l >= x && r <= y)
      return info[v];
    int m = (l + r) / 2;
    push(v);
    return query(2 * v, l, m, x, y) + query(2 * v + 1, m + 1, r, x, y);
  }
  Info query(int l, int r) { return query(1, 0, n - 1, l, r); }
};
struct tag {
  bool set = false;
  ll add = 0;
  void apply(tag t) {
    if (t.set) {
      set = true;
      add = t.add;
    } else
      add += t.add;
  }
};
struct node {
  ll val = 0;
  int sz = 1;
  friend node operator+(node lhs, node rhs) {
    return {lhs.val + rhs.val, lhs.sz + rhs.sz};
  }
  void apply(tag t) {
    if (t.set)
      val = t.add * sz;
    else
      val += t.add * sz;
  }
};


// Segment Tree
const ll inf = 1e18;
template <typename Info> struct seg_tree {
  int n;
  vector<Info> info;
  seg_tree(int n) : n(n), info(4 * n, Info()) {
    auto build = [&](auto &&self, int v, int l, int r) {
      if (l == r) {
        return;
      } else {
        int m = (l + r) / 2;
        self(self, v * 2, l, m);
        self(self, v * 2 + 1, m + 1, r);
        info[v] = info[v * 2] + info[v * 2 + 1];
      }
    };
    build(build, 1, 0, n - 1);
  }
  void pull(int v) { info[v] = info[v * 2] + info[v * 2 + 1]; }
  void update(int v, int l, int r, int x, const Info &val) {
    if (l == r) {
      info[v] = val;
      return;
    }
    int m = (l + r) / 2;
    if (x <= m)
      update(v * 2, l, m, x, val);
    else
      update(v * 2 + 1, m + 1, r, x, val);
    pull(v);
  }
  void update(int x, const Info &val) { update(1, 0, n - 1, x, val); }
  Info query(int v, int l, int r, int x, int y) {
    if (l > y || r < x)
      return Info();
    if (l >= x && r <= y)
      return info[v];
    int m = (l + r) / 2;
    pull(v);
    return query(2 * v, l, m, x, y) + query(2 * v + 1, m + 1, r, x, y);
  }
  Info query(int l, int r) { return query(1, 0, n - 1, l, r); }
  int lower_bound(int v, int l, int r, int x, int y, const Info& val) {
    if (l > y || r < x)
      return n;
    if (l == r) {
      return l;
    }
    int m = (l + r) / 2;
    if (info[v*2] >= val) {
      return lower_bound(v*2, l, m, x, y, val);
    } else {
      return lower_bound(v*2+1, m+1, r, x, y, val);
    }
  }
  int lower_bound(int l, int r, const Info& val) { return lower_bound(1, 0, n - 1, l, r, val); }
};


template<typename Info>
struct seg_node {
  unique_ptr<seg_node> left, right;
  Info v;
  seg_node() = default;
  void update(ll s, ll e, int x, Info v){
    if(s == e){
      this->v = this->v + v; 
      return;
    }
    ll m = (s + e) >> 1;
    if(x <= m){
      if(!left) left = make_unique<seg_node>();
      left->update(s, m, x, v);
    }else{
      if(!right) right = make_unique<seg_node>();
      right->update(m+1, e, x, v);
    }
    Info t1 = left ? left->v : Info();
    Info t2 = right ? right->v : Info();
    this->v = t1 + t2;
  }
  Info query(ll s, ll e, ll l, ll r){
    if(l > r || r < s || e < l) return Info();
    if(l <= s && e <= r) return v;
    ll m = (s + e) >> 1;
    return (left ? left->query(s, m, l, r) : Info()) + (right ? right->query(m+1, e, l, r) : Info());
  }
};

