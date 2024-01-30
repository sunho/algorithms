#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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
  void set(int v, int l, int r, int x, const Info &val) {
    if (l == r) {
      info[v] = val;
      return;
    }
    int m = (l + r) / 2;
    if (x <= m)
      set(v * 2, l, m, x, val);
    else
      set(v * 2 + 1, m + 1, r, x, val);
    pull(v);
  }
  void set(int x, const Info &val) { set(1, 0, n - 1, x, val); }
  Info query(int v, int l, int r, int x, int y) {
    if (l > y || r < x)
      return Info();
    if (l >= x && r <= y)
      return info[v];
    int m = (l + r) / 2;
    return query(2 * v, l, m, x, y) + query(2 * v + 1, m + 1, r, x, y);
  }
  Info query(int l, int r) { return query(1, 0, n - 1, l, r); }
};
struct node {
  ll val = 0;
  friend node operator+(node lhs, node rhs) { return {lhs.val+rhs.val}; }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, q;
  cin >> n >> q;
  seg_tree<node> st(n);
  for (int i=0;i<n;i++){
    int a;
    cin >> a;
    st.set(i, {a});
  }
  cout << "\n";
  while(q--){
    int t;
    cin >> t;
    if (t == 1) {
      int k,x;
      cin >> k >> x;
      --k;
      st.set(k,{x});
    } else {
      int l,r;
      cin >> l >> r;
      --l,--r;
      cout << st.query(l,r).val << "\n";
    }
  }
 
}
