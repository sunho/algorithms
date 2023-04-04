#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll inf = 1e18;

// Segment Tree for min query
struct seg_tree {
  int n;
  vector<ll> t;
  seg_tree(int n) : n(n), t(4*n, inf) {}

  // query the combinded value on [l,r]
  ll query(int l, int r, int v=1, int tl=0, int tr=-1) {
    if (tr == -1) tr = n-1;
    if (l > r) return inf;
    if (l == tl && r == tr) {
      return t[v];
    }
    int tm = (tl + tr) / 2;
    ll x = query(l, min(r,tm), v*2, tl, tm);
    ll y = query(max(tm+1,l), r, v*2+1, tm+1, tr);
    return min(x,y);
  }

  // update the node at pos
  void update(int pos, ll val, int v=1, int tl=0, int tr=-1) {
    if (tr == -1) tr = n-1;
    if (tl == tr) {
      t[v] = val;
      return;
    } 
    int tm = (tl + tr)/2;
    if (pos <= tm) {
      update(pos, val, v*2, tl, tm);
    } else {
      update(pos, val, v*2+1, tm+1,tr);
    }
    t[v] = min(t[v*2], t[v*2+1]);
  }
};


int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n,q;
  cin >> n >> q;
  seg_tree st(n), st2(n);
  for (int i=0;i<n;i++){
    int a;
    cin >> a;
    st.update(i, i+a);
    st2.update(i, (n-1-i)+a);
  }
  while(q--){
    int t;
    cin >> t;
    if (t == 1) {
      int a, v;
      cin >> a >> v;
      --a;
      st.update(a, a+v);
      st2.update(a, (n-a-1)+v);
    } else {
      int i;
      cin >> i;
      --i;
      cout << min(st2.query(0, i) - (n-1-i), st.query(i, n-1) - i) << "\n";
    }
  }
}
