#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll inf = 1e18;

// Segment Tree for min query
struct SegTree {
  int n;
  vector<pair<ll,ll>> t;
  SegTree(int n) : n(n), t(4*n, {0,0}) {}

  // query the combinded value on [l,r]
  pair<ll,ll> query(int l, int r, int v=1, int tl=0, int tr=-1) {
    if (tr == -1) tr = n-1;
    if (l > r) return {0,0};
    if (l == tl && r == tr) {
      return t[v];
    }
    int tm = (tl + tr) / 2;
    auto [x1,y1] = query(l, min(r,tm), v*2, tl, tm);
    auto [x2,y2] = query(max(tm+1,l), r, v*2+1, tm+1, tr);
    return {x1+x2, max(y1, x1+y2)};
  }

  // update the node at pos
  void update(int pos, int val, int v=1, int tl=0, int tr=-1) {
    if (tr == -1) tr = n-1;
    if (tl == tr) {
      t[v] = {val, max(0,val)};
      return;
    } 
    int tm = (tl + tr)/2;
    if (pos <= tm) {
      update(pos, val, v*2, tl, tm);
    } else {
      update(pos, val, v*2+1, tm+1,tr);
    }
    auto [x1,y1] = t[v*2];
    auto [x2,y2] = t[v*2+1];
    t[v] = {x1+x2, max({y1,x1+y2})};
  }
};


void solve() {
  int n, q;
  cin >> n >> q;
  SegTree st(n);
  for(int i=0;i<n;i++){
    int v;
    cin >> v;
    st.update(i, v);
  }
  while(q--){
    int t;
    cin >> t;
    if (t== 1){
      int i, v;
      cin >> i >> v;
      --i;
      st.update(i,v);
    } else {
      int l,r;
      cin >> l >> r;
      --l,--r;
      cout << st.query(l, r).second << "\n";
    }
  }
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
