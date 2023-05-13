#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<class Info> struct seg_tree {
  int n;
  vector<Info> info;
  seg_tree(int n) : n(n), info(4*n) {}

  void pull(int v) { info[v] = info[v*2] + info[v*2+1]; }
  void update(int v, int l, int r, int x, const Info& val) {
    if (l == r) {
      info[v] = val;
      return;
    }
    int m = (l + r) / 2;
    if (x <= m) update(v*2, l, m, x,  val);
    else update(v*2+1, m+1, r, x, val); 
    pull(v);
  }
  void update(int x, const Info& val) { update(1, 0, n-1, x, val); }
  Info query(int v, int l, int r, int x, int y) {
    if (l > y || r < x)
      return {};
    if (l >= x && r <= y)
      return info[v];
    int m = (l + r) / 2;
    pull(v);
    return query(2*v, l, m, x, y) + query(2*v+1, m+1, r, x, y);
  }
  Info query(int l, int r) { return query(1, 0, n-1, l, r); }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, q;
  cin >> n >> q;
  seg_tree<ll> st(n);
  for (int i=0;i<n;i++){
    int a;
    cin >> a;
    st.update(i, a);
  }
  while(q--){
    int t;
    cin >> t;
    if (t == 1) {
      int k,x;
      cin >> k >> x;
      --k;
      st.update(k,x);
    } else {
      int l,r;
      cin >> l >> r;
      --l,--r;
      cout << st.query(l,r) << "\n";
    }
  }

}
