#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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
  ll add = 0;
  void apply(tag t) {
    if (t.set) {
      set = true;
      add = t.add;
    } else {
      add += t.add;
    }
  }
};
struct node {
  ll val = 0;
  int sz = 1;
  friend node operator+(node lhs, node rhs) {
		return {lhs.val+rhs.val, lhs.sz+rhs.sz};
  }
  void apply(tag t) {
    if (t.set)
      val = t.add*sz;
    else
      val += t.add*sz;
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  
  int n,q;
  cin >> n >> q;
  lazy_seg_tree<node, tag> st(n);
  for (int i=0;i<n;i++){
    int a;
    cin >> a;
    st.update(i, {a,1});
  }

  while (q--){
    int t;
    cin >> t;
    if (t == 1) {
      int l,r,x;
      cin >> l >> r >> x;
      --l,--r;
      st.range_apply(l, r, {false, x});
    } else if (t == 2) {
      int l,r,x;
      cin >> l >> r >> x;
      --l,--r;
      st.range_apply(l, r, {true, x});
    } else {
      int l,r;
      cin >> l >> r;
      --l,--r;
      cout << st.query(l,r).val << "\n";
    }
  }
}
