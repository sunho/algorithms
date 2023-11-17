#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<ll> vals;

// Lazy Segment Tree
template<class Info, class Tag> struct lazy_seg_tree {
  int n;
  vector<Info> info;
  vector<Tag> lazy;
  lazy_seg_tree(int n) : n(n), info(4*n), lazy(4*n) {}
  void apply(int v, const Tag& tag) {
    info[v].apply(tag);
    lazy[v].apply(tag);
  }
  void push(int v) {
    apply(2*v, lazy[v]);
    apply(2*v+1, lazy[v]);
    lazy[v] = {};
  }
  void pull(int v) { info[v] = info[2*v] + info[2*v+1]; }
  void update(int v, int l, int r, int x, const Info& val) {
    if (l == r) {
      info[v] = val;
      return;
    }
    int m = (l + r) / 2;
    push(v);
    if (x <= m) update(2*v, l, m, x,  val);
    else update(2*v+1, m+1, r, x, val); 
    pull(v);
  }
  void update(int x, const Info& val) { update(1, 0, n-1, x, val); }
  void range_apply(int v, int l, int r, int x, int y, const Tag& tag) {
    if (l > y || r < x)
      return;
    if (l >= x && r <= y) {
      apply(v, tag);
      return;
    }
    int m = (l + r) / 2;
    push(v);
    range_apply(2*v, l, m, x, y, tag);
    range_apply(2*v+1, m+1, r, x, y, tag);
    pull(v);
  }
  void range_apply(int l, int r, const Tag& tag) { range_apply(1,0,n-1,l,r,tag); }
  Info query(int v, int l, int r, int x, int y) {
    if (l > y || r < x)
      return {};
    if (l >= x && r <= y)
      return info[v];
    int m = (l + r) / 2;
    push(v);
    return query(2*v, l, m, x, y) + query(2*v+1, m+1, r, x, y);
  }
  Info query(int l, int r) { return query(1, 0, n-1, l, r); }
};
struct tag {
  bool set = false;
  bool flip = false;
  int set_val = 0;
  tag() = default;
  void apply(tag t) {
    assert(!t.set || !t.flip);
    if (t.set) {
      set = true;
      set_val = t.set_val;
      flip = false;
    } else if (t.flip) {
      if (set) {
        set_val ^= 1;
      } else {
        flip ^= 1;
      }
    }
  }
};
struct node {
  ll val = 0;
  int l = -1, r = -1;
  node() = default;
  friend node operator+(node lhs, node rhs) {
    if (lhs.l == -1) return rhs;
    if (rhs.l == -1) return lhs;
    node res;
    res.val = lhs.val + rhs.val;
    res.l = lhs.l;
    res.r = rhs.r;
    return res;
  }
  void apply(tag t) {
    if (t.set) {
      val = t.set_val * (vals[r]-vals[l]);
      //cout << l << " " << r << " " << vals[r] - vals[l] << "\n";
      assert(!t.flip);
    }
    else if (t.flip) {
      val = (vals[r]-vals[l]) - val;
    }
  }
};

int main() {
  int n;
  cin >> n;
  vector<tuple<int,ll,ll>> queries;
  vals.push_back(0);
  for (int i=0;i<n;i++){
    ll t,l,r;
    cin >> t >> l >> r;
    for (int d=-4;d<=4;d++) {
      if (l+d >= 0)
        vals.push_back(l+d);
      if (r+d >= 0)
        vals.push_back(r+d);
    }
    queries.push_back({t,l,r});
  }
  sort(begin(vals),end(vals));
  vals.resize(unique(begin(vals),end(vals))-begin(vals));
  lazy_seg_tree<node, tag> st(vals.size());
  vals.push_back(vals.back()+1);
  for (int i=0;i<vals.size()-1;i++){
    st.update(i, {0, i, i+1});
  }
  for (int i=0;i<n;i++){
    auto [t,l,r] = queries[i];
    l = lower_bound(begin(vals),end(vals),l)-begin(vals);
    r = lower_bound(begin(vals),end(vals),r)-begin(vals);
    if (t == 1) {
      st.range_apply(l, r, {true, false, 1});
    } else if (t == 2) {
      st.range_apply(l, r, {true, false, 0});
    } else {
      st.range_apply(l, r, {false, true, 0});
    }
    int ok = 0, ng = vals.size()-2;
    while (ng - ok > 1) {
      int mid = (ok+ng)/2;
      if (st.query(0,mid).val + 1 == vals[mid+1]) {
        ok = mid;
      } else {
        ng = mid;
      }
    }
    cout << vals[ok] + 1 << "\n";
  }

}
