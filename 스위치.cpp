#include <bits/stdc++.h>

using namespace std;
using ll = long long;

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
  void apply(tag t) { set ^= t.set; }
};
struct node {
  ll val = 0;
  int sz = 1;
  friend node operator+(node lhs, node rhs) {
    return {lhs.val + rhs.val, lhs.sz + rhs.sz};
  }
  void apply(tag t) {
    if (t.set) {
      val = sz - val;
    }
  }
};

void solve() {
  int n, q;
  cin >> n >> q;
  lazy_seg_tree<node, tag> st(n);
  while (q--) {
    int t;
    cin >> t;
    int l, r;
    cin >> l >> r;
    --l, --r;
    if (t == 0) {
      st.range_apply(l, r, {true});
    } else {
      cout << st.query(l, r).val << "\n";
    }
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
